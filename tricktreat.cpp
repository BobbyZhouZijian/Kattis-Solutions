#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<double, double>> coords;

double f(double x ) {
    double maxm = 0.0;

    for (auto &p: coords) {
        maxm = max(maxm, hypot(p.first - x, p.second));
    }
    return maxm;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout << setprecision(7);
    while (cin >> N) {
        if (N == 0) break;
        coords.clear();
        double lo = 0, hi = 0;
        for (int i = 0; i < N; ++i) {
            double x, y;
            cin >> x >> y;
            lo = min(lo, x);
            hi = max(hi, x);
            coords.push_back({x, y});
        }
        while (hi - lo > 1e-7) {
            double l =(lo*2+hi) / 3;
            double r = (lo+hi*2) / 3;
            if (f(l) < f(r)) {
                hi = r;
            } else { 
                lo = l;
            }
        }
        cout << lo << " " << f(lo) << endl;
    }
}