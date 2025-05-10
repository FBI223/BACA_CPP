

#ifndef LAB6_RANGE_H
#define LAB6_RANGE_H


template<typename T>
class RangeIterator {
    T current;
    T step;

public:
    RangeIterator(T current, T step) : current(current), step(step) {
    }

    T operator*() const { return current; }


    RangeIterator operator++(int) {
        RangeIterator temp = *this;
        ++(*this);
        return temp;
    }

    RangeIterator &operator++() {
        current += step;
        return *this;
    }

    bool operator!=(const RangeIterator &other) const {
        return (step > 0) ? (current < other.current) : (current > other.current);
    }
};

template<typename T>
class Range {
    T start, stop, step;

public:
    Range(T stop) : start(0), stop(stop), step(1) {
    }

    Range(T start, T stop, T step = 1) : start(start), stop(stop), step(step) {
    }

    RangeIterator<T> begin() const { return RangeIterator<T>(start, step); }
    RangeIterator<T> end() const { return RangeIterator<T>(stop, step); }
};


template<typename T>
Range<T> make_range(T stop) {
    return Range<T>(stop);
}

template<typename T>
Range<T> make_range(T start, T stop, T step = 1) {
    return Range<T>(start, stop, step);
}


/*
for (auto x : Range<int>(1, 10, 2)) {
    std::cout << x << " ";
}



TO PRZEKSZTALCAMY W



auto __begin = Range<int>(1, 10, 2).begin();  // RangeIterator
auto __end = Range<int>(1, 10, 2).end();      // RangeIterator

while (__begin != __end) {
    auto x = *__begin;      // operator*(), czyli x = current
    std::cout << x << " ";  // wypisanie x
    ++__begin;              // operator++(), przesunięcie o step
}

*/


#endif //LAB6_RANGE_H
