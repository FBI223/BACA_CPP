#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    int value = 5; {
        /// sets coordinates to zero and checks indices
        using Vect = Vector<double, 3, SafePolicy>;
        Vect a{};

        try {
            a.set(1, -1); // OK
        } catch (const std::exception &e) {
            cout << "Exception in set(1, -1): " << e.what() << endl;
        }

        try {
            cout << a << endl; // 0 -1 0
        } catch (const std::exception &e) {
            cout << "Exception in printing a: " << e.what() << endl;
        }

        try {
            a.set(-1, 1.); // Exception
        } catch (const std::exception &e) {
            cout << "Exception in set(-1, 1.): " << e.what() << endl;
        }

        try {
            cout << a.get(3) << endl; // Exception
        } catch (const std::exception &e) {
            cout << "Exception in get(3): " << e.what() << endl;
        }

        try {
            Vect b{1, 2, 3, 4}; // Exception
        } catch (const std::exception &e) {
            cout << "Exception in initializer list: " << e.what() << endl;
        }
    } {
        /// does not initialize by default and does not check indices
        using Vect = Vector<double, 3, FastPolicy>;
        Vect a{};

        try {
            a.set(1, -1); // OK
        } catch (const std::exception &e) {
            cout << "Exception in set(1, -1): " << e.what() << endl;
        }

        try {
            cout << a << endl; // Unspecified (random values on first and third coordinate)
        } catch (const std::exception &e) {
            cout << "Exception in printing a: " << e.what() << endl;
        }

        try {
            a.set(-1, 1.); // Unspecified
        } catch (const std::exception &e) {
            cout << "Exception in set(-1, 1.): " << e.what() << endl;
        }

        try {
            cout << value << endl; // value possibly changed by the previous line
        } catch (const std::exception &e) {
            cout << "Exception in printing value: " << e.what() << endl;
        }

        try {
            cout << a.get(3) << endl; // Unspecified
        } catch (const std::exception &e) {
            cout << "Exception in get(3): " << e.what() << endl;
        }

        try {
            Vect b{1, 2, 3, 4}; // OK: it makes copy of only first three values
        } catch (const std::exception &e) {
            cout << "Exception in initializer list: " << e.what() << endl;
        }
    } {
        /// initializes to zero by default but does not check indices
        using Vect = Vector<double, 3, InitFastPolicy>;
        Vect a{};

        try {
            a.set(1, -1); // OK
        } catch (const std::exception &e) {
            cout << "Exception in set(1, -1): " << e.what() << endl;
        }

        try {
            cout << a << endl; // OK: 0 -1 0
        } catch (const std::exception &e) {
            cout << "Exception in printing a: " << e.what() << endl;
        }

        try {
            a.set(-1, 1.); // Unspecified
        } catch (const std::exception &e) {
            cout << "Exception in set(-1, 1.): " << e.what() << endl;
        }

        try {
            cout << value << endl; // value possibly changed by the previous line
        } catch (const std::exception &e) {
            cout << "Exception in printing value: " << e.what() << endl;
        }

        try {
            cout << a.get(3) << endl; // Unspecified
        } catch (const std::exception &e) {
            cout << "Exception in get(3): " << e.what() << endl;
        }

        try {
            Vect b{1, 2, 3, 4}; // OK: it makes copy of only first three values
        } catch (const std::exception &e) {
            cout << "Exception in initializer list: " << e.what() << endl;
        }
    }

    return 0;
}
