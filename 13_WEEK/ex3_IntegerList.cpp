

#include <iostream>
#include <iomanip>


using namespace std;


template<int... Ints>
struct IntegerList {
};


template<int Index, typename List>
struct getInt;


template<int Head, int... Tail>
struct getInt<0, IntegerList<Head, Tail...> > {
    static constexpr int value = Head;
};

template<int Index, int Head, int... Tail>
struct getInt<Index, IntegerList<Head, Tail...> > {
    static constexpr int value = getInt<Index - 1, IntegerList<Tail...> >::value;
};


template<typename A, typename B>
struct Join;

template<int... A, int... B>
struct Join<IntegerList<A...>, IntegerList<B...> > {
    using type = IntegerList<A..., B...>;
};


template<typename List>
struct IsSorted;

template<>
struct IsSorted<IntegerList<> > {
    static constexpr bool value = true;
};

template<int A>
struct IsSorted<IntegerList<A> > {
    static constexpr bool value = true;
};

template<int A, int B, int... Rest>
struct IsSorted<IntegerList<A, B, Rest...> > {
    static constexpr bool value = (A <= B) && IsSorted<IntegerList<B, Rest...> >::value;
};


template<typename List>
struct Max;

template<int A>
struct Max<IntegerList<A> > {
    static constexpr int value = A;
};

template<int A, int B, int... Rest>
struct Max<IntegerList<A, B, Rest...> > {
    static constexpr int value = (A > Max<IntegerList<B, Rest...> >::value) ? A : Max<IntegerList<B, Rest...> >::value;
};


template<typename List>
void printList() {
    printListImpl(List{});
}


void printListImpl(IntegerList<>) {
    cout << endl;
}


template<int Head, int... Tail>
void printListImpl(IntegerList<Head, Tail...>) {
    cout << Head;
    if constexpr (sizeof...(Tail) > 0) {
        cout << ", ";
        printListImpl(IntegerList<Tail...>{});
    } else {
        cout << endl;
    }
}


int main() {
    using listA = IntegerList<5, -1, 5, 2, 1>;
    using listB = IntegerList<1, 4, 6, 9>;
    using listC = Join<listA, listB>::type;

    cout << "List A: ";
    printList<listA>();

    cout << "List B: ";
    printList<listB>();

    cout << "listA[1] = " << getInt<1, listA>::value << endl;
    cout << "listB[3] = " << getInt<3, listB>::value << endl;

    cout << "List C: ";
    printList<listC>();

    cout << boolalpha;
    cout << "Is A sorted? " << IsSorted<listA>::value << endl;
    cout << "Is B sorted? " << IsSorted<listB>::value << endl;

    cout << "Max in listC (template): " << Max<listC>::value << endl;
}


/*

#include <iostream>
#include <array>
using namespace std;


template<int... Ints>
struct IntegerList {
    static constexpr std::array<int, sizeof...(Ints)> data = {Ints...};

    static constexpr int get(int index) {
        return data[index];
    }

    static constexpr int max() {
        int m = data[0];
        for (int i = 1; i < data.size(); ++i)
            if (data[i] > m) m = data[i];
        return m;
    }

    constexpr const char *operator()() const {
        return toString();
    }

    static const char *toString() {
        return "IntegerList"; // fallback placeholder
    }
};

// Definicja static constexpr array poza klasą (wymagane w C++)
//template<int... Ints>
//constexpr std::array<int, sizeof...(Ints)> IntegerList<Ints...>::data;


template<int Index, typename List>
struct getInt {
    static constexpr int value = List::data[Index];
};


template<typename A, typename B>
struct Join;

template<int... A, int... B>
struct Join<IntegerList<A...>, IntegerList<B...> > {
    using type = IntegerList<A..., B...>;
};


template<typename List>
struct IsSorted;

template<int... Ints>
struct IsSorted<IntegerList<Ints...> > {
private:
    static constexpr bool check() {
        constexpr auto &arr = IntegerList<Ints...>::data;
        for (size_t i = 1; i < arr.size(); ++i)
            if (arr[i - 1] > arr[i])
                return false;
        return true;
    }

public:
    static constexpr bool value = check();
};


template<typename List>
struct Max;

template<int... Ints>
struct Max<IntegerList<Ints...> > {
private:
    static constexpr int compute() {
        constexpr auto &arr = IntegerList<Ints...>::data;
        int m = arr[0];
        for (size_t i = 1; i < arr.size(); ++i)
            if (arr[i] > m)
                m = arr[i];
        return m;
    }

public:
    static constexpr int value = compute();
};


template<int... Ints>
ostream &operator<<(ostream &os, IntegerList<Ints...>) {
    constexpr auto arr = IntegerList<Ints...>::data;
    for (size_t i = 0; i < arr.size(); ++i) {
        os << arr[i];
        if (i + 1 < arr.size()) os << ", ";
    }
    return os;
}

int main() {
    using listA = IntegerList<5, -1, 5, 2, 1>;
    using listB = IntegerList<1, 4, 6, 9>;

    cout << "List A : " << listA() << endl;
    cout << "List B : " << listB() << endl;

    cout << getInt<1, listA>::value << endl;
    cout << listB::get(3) << endl;

    using listC = Join<listA, listB>::type;
    cout << "List C : " << listC() << endl;

    cout << boolalpha;
    cout << "Is A sorted? " << IsSorted<listA>::value << endl;
    cout << "Is B sorted? " << IsSorted<listB>::value << endl;

    cout << Max<listC>::value << endl;
    cout << listC::max() << endl;
}
*/
