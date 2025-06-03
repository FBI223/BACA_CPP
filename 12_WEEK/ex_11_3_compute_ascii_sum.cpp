#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <string>
#include <future>
#include <map>

using namespace std;

// Funkcja do obliczania sumy ASCII i zwracania wyniku przez promise
void compute_ascii_sum(const string &filename, promise<int> result_promise) {
    ifstream file(filename);
    int sum = 0;
    char ch;

    if (file.is_open()) {
        while (file.get(ch)) {
            sum += static_cast<unsigned char>(ch); // uwzględnia znaki binarne
        }
        file.close();
    } else {
        cerr << "Cannot open file: " << filename << endl;
    }

    result_promise.set_value(sum);
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " file1.txt file2.txt ..." << endl;
        return 1;
    }

    vector<future<int> > futures; // futures — do pobrania wyników z wątków.
    vector<string> filenames;
    vector<thread> threads;

    // uruchamiamy wątek dla każdego pliku
    for (int i = 1; i < argc; ++i) {
        string filename = argv[i];
        filenames.push_back(filename);

        promise<int> prom;
        futures.push_back(prom.get_future());
        threads.emplace_back(compute_ascii_sum, filename, move(prom));
    }

    // czekamy na wszystkie wątki
    for (auto &t: threads) {
        t.join();
    }

    // zbieranie wyników
    map<int, vector<string> > sum_to_files;
    for (size_t i = 0; i < futures.size(); ++i) {
        int sum = futures[i].get();
        sum_to_files[sum].push_back(filenames[i]);
    }

    // wypisywanie par z tymi samymi sumami
    cout << "Matching ASCII sums:" << endl;
    for (const auto &[sum, files]: sum_to_files) {
        if (files.size() > 1) {
            cout << "Sum " << sum << " found in files: ";
            for (const auto &f: files) cout << f << " ";
            cout << endl;
        }
    }

    return 0;
}


/*
g++ ex_11_3_compute_ascii_sum.cpp -std=c++17 -pthread -o ascii_sum
./ascii_sum file1.txt file2.txt file3.txt




file1.txt zawiera ABC → ASCII sum = 65 + 66 + 67 = 198

file2.txt zawiera DEF → ASCII sum = 68 + 69 + 70 = 207

file3.txt zawiera CAB → ASCII sum = 67 + 65 + 66 = 198





std::promise<T> — obiekt, do którego można w jednym wątku wpisać wynik.

std::future<T> — obiekt, z którego można w innym wątku odebrać wynik, gdy będzie gotowy.

To para służąca do bezpiecznego przekazywania wyniku z wątku podrzędnego do głównego.





*/








