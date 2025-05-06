

#ifndef LAB8_VECTOR_H_TRAITS
#define LAB8_VECTOR_H_TRAITS


#include <type_traits>
#include <string>

using namespace std;

template<typename T>
struct vector_traits {
    using value_type = T;

    // Jak przekazywać parametry do get/set
    using param_type = const T &;
    using return_type = const T &;

    // Domyślny typ skalaru
    using scalar_type = T;


    static T multiply(const T &a, const T &b) {
        return a * b;
    }


    // Wartość domyślna
    static T default_value() {
        return T{};
    }
};


// Specjalizacja dla int
template<>
struct vector_traits<int> {
    using value_type = int;
    using param_type = int;
    using return_type = int;
    using scalar_type = int;

    static int multiply(const scalar_type &a, const int &b) {
        return a * b;
    }

    static int default_value() {
        return 0;
    }
};

// Specjalizacja dla double
template<>
struct vector_traits<double> {
    using value_type = double;
    using param_type = double;
    using return_type = double;
    using scalar_type = double;

    static double multiply(const scalar_type &a, const double &b) {
        return a * b;
    }

    static double default_value() {
        return 0.0;
    }
};

// Specjalizacja dla std::string
template<>
struct vector_traits<std::string> {
    using value_type = std::string;
    using param_type = const std::string &;
    using return_type = const std::string &;
    using scalar_type = int;

    static std::string multiply(int count, const std::string &s) {
        std::string result;
        for (int i = 0; i < count; ++i)
            result += s;
        return result;
    }

    static std::string default_value() {
        return "0";
    }
};


#endif // LAB8_VECTOR_H_TRAITS

