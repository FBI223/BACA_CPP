#include <iostream>
#include <cstring>
using namespace std;

struct Rational{
		int nominator=0, denominator=1;
		friend bool operator<(const Rational & a, const Rational & b){
			return a.nominator*b.denominator < b.nominator*a.denominator;
		}
};



// Base template
template<typename T>
int compare(T a, T b) {
	if (a < b) return 1;
	if (b < a) return -1;
	return 0;
}

// Pointer overload
template<typename T>
int compare(T* a, T* b) {
	return compare(*a, *b);
}

// Specialization for const char*
template<>
int compare<const char*>(const char* a, const char* b) {
	int res = strcmp(a, b);
	if (res < 0) return -1;
	if (res > 0) return 1;
	return 0;
}




int main(){
	int a = 1, b=-6;
	float  y= 1.0 + 1e20 - 1e20, x = 1.0;
	Rational p{2}, q{1,4}, r{8,4};
	cout << "values\n";
	cout << compare(a,b) << " " << compare(b,a) << " " << compare(a,a) << endl;
	cout << compare(x,y) << " " << compare(y,x) << " " << compare(x,x) << endl;
	cout << compare(p,q) << " " << compare(q,p) << " " << compare(p,r) << endl;
	cout << "pointers\n";
	cout << compare(&a,&b) << " " << compare(&b,&a) << " " << compare(&a,&a) << endl;
	cout << compare(&x,&y) << " " << compare(&y,&x) << " " << compare(&x,&x) << endl;
	cout << compare(&p,&q) << " " << compare(&q,&p) << " " << compare(&p,&r) << endl;
	
	const char *s  = "Alpha", *t="Alfa", *t2 = "Alfa"; 
	cout << "C-strings\n";
	cout << compare(s,t) << " " << compare(t,s) << " " << compare(t,t) 
	     << " " << compare(t, t2) << " " << compare(t, "Beta") << endl;
	
	return 0;
}
