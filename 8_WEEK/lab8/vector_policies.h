
#ifndef LAB8_VECTOR_H_POLICIES
#define LAB8_VECTOR_H_POLICIES


#include <stdexcept>
#include <cstddef>
#include "vector_traits.h"

using namespace std;


struct initZero {
    template<typename T, size_t N>
    static void init(T (&data)[N]) {
        for (size_t i = 0; i < N; ++i)
            data[i] = vector_traits<T>::default_value();
    }
};


struct initNone {
    template<typename T, size_t N>
    static void init(T (&)[N]) {
        // brak inicjalizacji
    }
};


struct checkBounds {
    static void check(size_t index, size_t size) {
        if (index >= size)
            throw std::out_of_range("Out of bounds");
    }
};

struct noCheck {
    static void check(size_t, size_t) {
        // brak sprawdzania
    }
};


template<typename InitPolicy, typename CheckPolicy>
struct CombinedPolicy {
    template<typename T, size_t N>
    static void init(T (&data)[N]) {
        InitPolicy::init(data); // NIE szablon → brak `template`
    }

    static void check(size_t index, size_t size) {
        CheckPolicy::check(index, size);
    }
};

// Predefiniowane aliasy
using InitFastPolicy = CombinedPolicy<initZero, noCheck>; // initialize but no checks
using InitSafePolicy = CombinedPolicy<initZero, checkBounds>; // initialize + checks
using SafePolicy = CombinedPolicy<initZero, checkBounds>;
using FastPolicy = CombinedPolicy<initNone, noCheck>;

#endif  LAB8_VECTOR_H_POLICIES

