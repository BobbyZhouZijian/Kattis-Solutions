#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> v;

double f(double x) {
    double minm = 1000000, maxm = -1000000;
    for (auto &p : v) {
        double pos = p.first + p.second * x;
        minm = min(minm, pos);
        maxm = max(maxm, pos);
    }
    return maxm - minm;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b; cin >> a>> b;

        v.push_back({a, b});
    }

    double lo = 0.0, hi = 200002.0;

    while (hi - lo > 1e-6) {
        double l = (lo*2+hi) / 3;
        double r= (lo+hi*2) / 3;

        double d1 = f(l), d2 = f(r);
        if (d1 < d2) {
            hi = r;
        } else {
            lo = l;
        }
    }
    cout << setprecision(5);
    // cout << lo << " " << hi << endl;
    cout << f(lo) << endl;
}