#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-12;
double t;
int n;

struct veg {
    double l;
    int cut;
    int idx;

    bool operator<(const veg& other) const {
        double d1 = this->l / this->cut;
        double d2 = other.l / other.cut;
        if (abs(d1-d2) < EPS) {
            if (this->l == other.l) return this->idx < other.idx;
            return this->l > other.l; 
        }
        return d1 < d2;
    }
};

set<veg> s;

bool check() {
    auto v1 = *s.begin(), v2 = *prev(s.end());
    double d1 = v1.l / v1.cut;
    double d2 = v2.l / v2.cut;

    if (d1 < d2) return d1 / d2 >= t;
    else return d2 / d1 >= t;
}



int main() {
    scanf("%lf%d", &t, &n);
    for (int i = 0; i < n; ++i) {
        double x; cin >> x;
        s.insert({x,1,i});
    }
    
    int ans = 0;
    while (!check()) {
        auto v = *prev(s.end());
        veg new_v = {v.l, v.cut+1, v.idx};
        s.erase(v);
        s.insert(new_v);
        ans++;
    }
    
    printf("%d\n", ans);
}
