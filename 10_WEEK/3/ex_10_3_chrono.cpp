#include <iostream>
#include <chrono>
#include <iomanip>
#include <string>
#include <utility>


using namespace std;

class Timer {
    std::string name;
    std::chrono::steady_clock::time_point start;

public:
    explicit Timer(std::string name) : name(std::move(name)), start(std::chrono::steady_clock::now()) {
    }

    ~Timer() {
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << std::fixed << std::setprecision(6)
                << name << " : " << duration / 1000.0 << " ms.\n";
    }

    [[nodiscard]] long long durationInNanoseconds() const {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(now - start).count();
    }
};


long fibonacci(unsigned n) {
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    Timer total("Total time");
    for (auto n: {1, 5, 15, 20, 25, 40, 45}) {
        {
            Timer t("fibonacci(" + std::to_string(n) + ")");
            fibonacci(n);
        }
    }
    std::cout << "Elapsed " << total.durationInNanoseconds() << " ns.\n";
}

/** Expected output similar to:

fibonacci(1) : 0.000619 ms.
fibonacci(5) : 0.000891 ms.
fibonacci(15) : 0.01025 ms.
fibonacci(20) : 0.094905 ms.
fibonacci(25) : 1.04443 ms.
fibonacci(40) : 989.97 ms.
fibonacci(45) : 8537.47 ms.
Elapsed 9528821533 ns.
Total time : 9528.84 ms.
*/
