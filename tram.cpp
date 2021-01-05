#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<double, double>> v;

double f(double x) {
    double ans = 0;
    for (auto &p : v) {
        ans += pow(p.first - p.second + x, 2);
    }
    return ans;
}

int main() {
    cin >> N;
    double x, y;
    double lo = 9999999, hi = -9999999;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        v.push_back({x, y});
        lo = min(lo, y-x);
        hi = max(hi, y-x);
    }
    while (hi - lo > 1e-5) {
        double l = (lo*2+hi) / 3;
        double r = (lo+hi*2) / 3;
        if (f(l) < f(r)) {
            hi = r;
        } else {
            lo = l;
        }
    }
    cout << lo << endl;
}