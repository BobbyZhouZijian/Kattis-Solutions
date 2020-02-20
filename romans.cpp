#include<iostream>
#include<cmath>
using namespace std;


template<typename T>
void DEBUG(T x) { cout << x << " DEBUG" << endl; }

int main() {

    double mile, convert; cin >> mile;

    convert = mile * (5280.0 / 4854.0) * 1000.0;
    cout << (int) round(convert);
    return 0;
}