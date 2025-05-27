
#include <iostream>
#include <vector>
#include <concepts>

using namespace std;

template<typename T>
class A {
protected:
    T x;

public:
    A(T x = T()) : x(x) {
    }

    void print() const {
        cout << "[" << x << "]";
    }

    friend A operator+(const A &a, const A &b) {
        return A(a.x + b.x);
    }

    template<typename U>
    friend class B;
};


template<typename T>
class B : public A<T> {
public:
    using A<T>::A;

    B(const A<T> &a) : A<T>(a) {
    }

    friend std::ostream &operator<<(std::ostream &out, const B &b) {
        return (out << "#" << b.x << "#");
    }

    friend B operator+(const B &a, const B &b) {
        return B(a.x + b.x);
    }
};


template<typename T>
concept HasOstreamOperator = requires(std::ostream &os, T t)
{
    { os << t } -> std::same_as<std::ostream &>;
};


/*
  { os << t } — sprawdza, czy można wykonać operację os << t, czyli czy operator << jest zdefiniowany dla typu T.

-> std::same_as<std::ostream &> — dodatkowo sprawdza, czy wynik tej operacji ma dokładnie typ std::ostream&.
*/
template<typename T>
concept HasPrintMethod = requires(T t)
{
    { t.print() } -> std::same_as<void>;
};

template<typename T>
concept HasValueType = requires { typename T::value_type; };

template<typename T>
concept Iterable = requires(T t)
{
    { t.begin() } -> std::input_iterator;
    { t.end() } -> std::sentinel_for<decltype(t.begin())>;
};

template<typename T>
concept AddableElements = requires(typename T::value_type a, typename T::value_type b)
{
    { a + b } -> std::same_as<typename T::value_type>;
};


template<typename T>
concept Container = HasValueType<T> && Iterable<T> && AddableElements<T>;

/*
template<typename T>
concept Container = requires
{
    requires HasValueType<T>;
    requires Iterable<T>;
    requires AddableElements<T>;
};
*/

// === print ===
template<typename T> requires HasOstreamOperator<T> && (!Container<T>)
void print(const T &obj) {
    cout << obj << endl;
}


template<typename T> requires (!HasOstreamOperator<T> && HasPrintMethod<T> && !Container<T>)
void print(const T &obj) {
    obj.print();
    cout << endl;
}

template<Container T>
void print(const T &container) {
    int i = 0;
    for (const auto &elem: container) {
        std::cout << i++ << " : ";
        print(elem); // w zaleznosci od typu przechowywanego
    }
    std::cout << "-------" << std::endl;
}


// === sum ===
template<Container T> // kontener juz zawiera concepts
auto sum(const T &container) {
    typename T::value_type result{};
    for (const auto &e: container)
        result = result + e;
    return result;
}

// === main ===
int main() {
    vector v{1, 2, 4, 5};
    print(v);

    A<int> a{5};
    print(a);

    B<double> b{3.14};
    print(b);

    print(2.7);

    vector<A<int> > va{4, 5, 7, 9};
    vector<B<int> > vb{4, 5, 7, 9};
    print(va);
    print(vb);

    print(sum(v));
    print(sum(vb));

    return 0;
}


/**
* Expected output
0 : 1
1 : 2
2 : 4
3 : 5
-------
[5]
#3.14#
2.7
0 : [4]
1 : [5]
2 : [7]
3 : [9]
-------
0 : #4#
1 : #5#
2 : #7#
3 : #9#
-------
12
#25#
*/
