
#ifndef LAB6_FILTER_H
#define LAB6_FILTER_H


#include <utility>


template<typename Container, typename Predicate>
class Filter {
    Container container;
    Predicate predicate;

    using RawContainer = std::remove_reference_t<Container>;

public:
    class iterator {
        typename RawContainer::iterator current;
        typename RawContainer::iterator end;
        Predicate *predicate;

        void skip_invalid() {
            while (current != end && !(*predicate)(*current)) {
                ++current;
            }
        }

    public:
        iterator(typename RawContainer::iterator it,
                 typename RawContainer::iterator ed,
                 Predicate *pred)
            : current(it), end(ed), predicate(pred) {
            skip_invalid();
        }

        auto &operator*() { return *current; }

        iterator &operator++() {
            ++current;
            skip_invalid();
            return *this;
        }

        bool operator!=(const iterator &other) const {
            return current != other.current;
        }
    };

    Filter(Container &&c, Predicate p)
        : container(std::forward<Container>(c)), predicate(std::move(p)) {
    }

    iterator begin() {
        return iterator(container.begin(), container.end(), &predicate);
    }

    iterator end() {
        return iterator(container.end(), container.end(), &predicate);
    }
};

template<typename Container, typename Predicate>
auto make_filter(Container &&c, Predicate p) {
    return Filter<Container &&, Predicate>(std::forward<Container>(c), p);
}

#endif //LAB6_FILTER_H
