#include <iostream>
using namespace std;


constexpr long double operator"" _m(long double val) { return val; }
constexpr long double operator"" _km(long double val) { return val * 1000.0; }
constexpr long double operator"" _cm(long double val) { return val / 100.0; }


constexpr long double operator"" _s(long double val) { return val; }
constexpr long double operator"" _ms(long double val) { return val / 1000.0; }
constexpr long double operator"" _h(long double val) { return val * 3600.0; }

/**
    Computes velocity in meters per seconds.
    @param distance  distance in meters
    @param time      time in seconds
    @return velocity in meters per seconds.
*/
double computeVelocity(double distance, double time) {
    return distance / time;
}

int main() {
    cout << computeVelocity(100.0_m, 5.0_s) << endl; // 20
    cout << computeVelocity(360.0_km, 2.0_h) << endl; // 50
    cout << computeVelocity(3.6_km, 0.02_h) << endl; // 50
    cout << computeVelocity(250.0_cm, 2.5_ms) << endl; // 1000
    return 0;
}
