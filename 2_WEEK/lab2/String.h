#include <iostream>
#include <algorithm>
#include <memory>
#include "MyString.h"
using namespace std;

class String{
    using string = emcpp::MyString;
    shared_ptr<string> myString;

//    using string = std::string;

/// Store a pointer to dynamically allocated string!

public:
    String() : myString(make_shared<string>()) {}   /// creates an empty string
    String(const char * str) : myString(make_shared<string>(str)) {} ;          /// copy C-string
    String(const String & other ) : myString(other.myString){};            /// no copy
    String &operator=(const String &other) {
        if (this != &other) {
            myString = other.myString;
        }
        return *this;
    } /// no copy

    /// makes a copy of a string if it has more than one reference.
    void set(int index, char ch) {
        if (myString.use_count() > 1) {
            myString = make_shared<string>(*myString);  // Tworzymy nową kopię `MyString`
        }
        (*myString)[index] = ch;  // Teraz możemy bezpiecznie zmieniać dane
    }

    /// no copy
    char get(int index) const {
        return (index >= 0 && index < myString->size()) ? (*myString)[index] : '\0';
    }
    /// creates a new string only if both strings are non empty

    friend String operator+(const String &a, const String &b) {
        if (a.myString->empty() || b.myString->empty()) return {};
        return {(*a.myString + *b.myString).c_str()};
    }

    friend ostream &operator<<(ostream &out, const String &s) {
        return out << *s.myString;
    }
};
