
#pragma once
#include "vector_base.h"
#include "staticVector.h"
#include "dynamicVector.h"

template<typename T, std::size_t N>
Vector<T, N> operator+(const Vector<T, N>& a, const Vector<T, 0>& b) {
    if (b.size() != N) throw VectorException("Static + dynamic size mismatch");
    Vector<T, N> result;
    for (std::size_t i = 0; i < N; ++i)
        result[i] = a[i] + b[i];
    return result;
}

template<typename T, std::size_t N>
Vector<T, N> operator+(const Vector<T, 0>& a, const Vector<T, N>& b) {
    return b + a;
}

