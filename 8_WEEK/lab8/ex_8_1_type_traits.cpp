#include <limits>
#include <iostream>
#include <iomanip>


#include <type_traits>


using namespace std;
/**
 * Outputs information about numerical type T:
 * (un)signed, (not) integer, min & max values
*/


template<typename T>
void info(T x) {
    using Traits = std::numeric_limits<T>;

    cout << left << setw(20) << typeid(T).name() << " | ";

    // Sprawdzenie cech typu
    cout << (is_integral<T>::value ? "integer" : "not integer") << ", ";
    cout << (is_signed<T>::value ? "signed" : "unsigned") << " | ";

    // Zakres wartości
    cout << "min: " << Traits::min() << ", ";
    cout << "max: " << Traits::max() << endl;
}


template<typename T>
void infoinfo(T value, int w = 20) {
    std::cout << std::setw(w) << std::left << typeid(T).name() << " | " << std::right
            << std::setw(w) << std::numeric_limits<T>::min() << " | "
            << std::setw(w) << std::numeric_limits<T>::max() << " | "
            << std::setw(w) << std::numeric_limits<T>::epsilon() << " | "
            << std::endl;
}

int main() {
    info(1);
    info(2.0f);
    info(3U);
    return 0;
}

/**
 * Expected output:
    signed,  integer, min : -2147483648 max : 2147483647
    signed, not integer, min : 1.17549e-38 max : 3.40282e+38
    unsigned,  integer, min : 0 max : 4294967295
 */
