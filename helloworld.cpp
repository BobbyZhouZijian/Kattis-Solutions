#include <iostream>
using namespace std;

int N = 10;

template<typename T>
T sum(T a, T b) { return a + b; }

int main() {

    cout << sum(3, 4) << "\n";
    cout << sum(4.0, 5.3);
}