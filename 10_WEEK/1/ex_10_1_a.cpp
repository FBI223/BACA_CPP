#include <iostream>


// --- Trait: hasSize<T> ---
template<typename, typename = void>
struct hasSize : std::false_type {
};

template<typename T>
struct hasSize<T, std::void_t<decltype(std::declval<T>().size())> > : std::true_type {
};

// declval Udajmy, że mamy obiekt typu T, bez tworzenia go
// decltype(5)    daje  int
// std::void_t<T>    Zwróć void, jeśli typ T istnieje i jest poprawny. Jeśli nie — SFINAE."


// std::void_t<decltype(std::declval<T>().size())>
// "Spróbuj sprawdzić typ wyniku T().size()."
// Jeśli T ma metodę .size() → OK → całość zwraca void
// Jeśli nie ma → błąd w decltype(...) → SFINAE → odrzuć to w kompilacji i zwroc
// zwroc domyslna wersje czyli false


// --- Trait: hasValueType<T> ---
template<typename, typename = void>
struct hasValueType : std::false_type {
};

template<typename T>
struct hasValueType<T, std::void_t<typename T::value_type> > : std::true_type {
};



