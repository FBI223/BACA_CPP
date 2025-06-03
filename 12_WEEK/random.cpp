#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cctype>
#include <ctime>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

template<int N>
struct Array {
    int a[N];
    long long sum = 0;

    int f(int x) {
        int y = x % 11;
        return (y * y + 1);
    }

    void generateArray(int numThreads) {
        auto worker = [&](int start, int end) {
            for (int i = start; i < end; ++i) {
                a[i] = f(rand());
            }
        };

        vector<thread> threads;
        int chunk = N / numThreads;
        for (int t = 0; t < numThreads; ++t) {
            int start = t * chunk;
            int end = (t == numThreads - 1) ? N : (t + 1) * chunk;
            //threads.emplace_back(worker, start, end); // tworzenie nowego watku
            //lub
            threads.push_back(std::thread(worker, start, end));
        }
        for (auto &t: threads) t.join(); // czekanie az watki sie skoncza wszystkie
    }

    long long computeSum(int numThreads) {
        sum = 0;
        vector<thread> threads;
        vector<long long> partialSums(numThreads, 0);

        auto worker = [&](int tid, int start, int end) {
            long long localSum = 0;
            for (int i = start; i < end; ++i) {
                localSum += a[i];
            }
            partialSums[tid] = localSum;
        };

        int chunk = N / numThreads;
        for (int t = 0; t < numThreads; ++t) {
            int start = t * chunk;
            int end = (t == numThreads - 1) ? N : (t + 1) * chunk;
            threads.emplace_back(worker, t, start, end);
        }
        for (auto &t: threads) t.join();

        sum = accumulate(partialSums.begin(), partialSums.end(), 0LL);
        return sum;
    }
};

int main() {
    srand(2019);
    using A = Array<1000>;
    A array;

    int numThreads = 4;
    array.generateArray(numThreads);

    for (int i = 0; i < 40; i++) {
        cout << array.a[i] << "  ";
    }

    long long sum = array.computeSum(numThreads);
    cout << "\nsum = " << sum << endl;

    return 0;
}
