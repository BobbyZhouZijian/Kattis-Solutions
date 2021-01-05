#include <bits/stdc++.h>
using namespace std;

int N;

double f(double h, double x, double y) {
    double b = y-2*h, a = x-2*h;
    return a * b * h;
}

int main() {
    cin >> N;
    cout << setprecision(7);

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        if (x < y) {
            swap(x, y);
        }
        double lo = 0.0, hi = y / 2;

        while (hi - lo > 1e-8) {
            double l = (lo*2+hi)/3;
            double r = (lo+hi*2)/3;
            if (f(l, x, y) < f(r, x, y)) {
                lo = l;
            } else {
                hi = r;
            }
        }
        cout << f(lo, x, y) << endl;
    }
}