


// std::enable_if<warunek, typ>::type
// Jeśli warunek jest true, to daje typ typ
// Jeśli warunek jest false, to powoduje SFINAE — czyli kompilator ignoruje
// daną funkcję lub szablon, zamiast zgłosić błąd


namespace v1 {
    template<typename T>
    typename std::enable_if<
        hasSize<T>::value && hasValueType<T>::value,
        size_t
    >::type
    getSize(const T &x) {
        return x.size() * sizeof(typename T::value_type);
    }


    // To jest wariant funkcji szablonowej getSize, który działa tylko wtedy, gdy typ T NIE ma:
    // metody .size
    // typu t::value:type


    template<typename T>
    typename std::enable_if<
        !(hasSize<T>::value && hasValueType<T>::value),
        size_t
    >::type
    getSize(const T &x) {
        return sizeof(x);
    }
}


namespace v2 {
    template<typename T>
    size_t getSize(const T &x) {
        if constexpr (hasSize<T>::value && hasValueType<T>::value) {
            return x.size() * sizeof(typename T::value_type);
        } else {
            return sizeof(x);
        }
    }
}





