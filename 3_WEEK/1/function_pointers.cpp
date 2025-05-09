#include <iostream>
#include <cmath>
using namespace std;
/// Computes n-th root of x
double sqrtn(int n, double x){
	return exp( log(x) / n);
}
double power(double  x, double y){
	return exp( log(x) * y);
}
template <typename F, typename G>
double function(int n, double y, double z, F f, G g){
	return (f(n,y) > z) ? g(z, y) : g(y, z);
}


double(*fp1)(int,double) = sqrtn;
double(*fp2)(double,double) = power;
double(*fp3)(int,double,double, double (*)(int, double), double (*)(double, double)) = function;

double **(*(*(*foo[8])(int, double))(int (*)()))[];

//auto add(auto a, auto b) { return a + b; }

int main(){
    cout << fp3(2, 10, 3, fp1, fp2) << endl;
    cout << fp3(3, 10, 3, fp1, fp2) << endl;
    return 0;
}
