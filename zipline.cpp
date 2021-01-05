#include <bits/stdc++.h>
using namespace std;

int w,g,h,r;

double f(double x) {
    return hypot(g-r, x) + hypot(h-r, w-x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cout << setprecision(14);
    int N;
    cin >> N;
    while (N--) {
        cin >> w>> g >>h >> r;
        double minm = hypot(w, abs(g-h));
        double lo = 0, hi = w;
        while (hi - lo > 1e-7) {
            double l = (lo*2+hi) / 3;
            double r = (lo+hi*2) / 3;
            // cout << l << " " << r << endl;
            // cout << f(l) << " " << f(r) << endl;
            if (f(l) > f(r)) {
                lo = l;
            } else {
                hi = r;
            }
        }
        cout << minm << " " << f(lo) << endl;
    }
}