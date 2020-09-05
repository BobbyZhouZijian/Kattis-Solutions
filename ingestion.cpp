#include <bits/stdc++.h>
using namespace std;

int n, m;
map<pair<int, int>, int> g;

int search(vector<int> &v, int hour, int capacity) {
    if (hour >= n) return 0;

    int ans = min(v[hour], capacity);
    // eat now
    auto tp1 = make_pair(hour + 1, capacity * 2 / 3);
    if (g.find(tp1) == g.end()) {
        g[tp1] = search(v, tp1.first, tp1.second);
    }
    auto tp2 = make_pair(hour + 3, m);
    if (g.find(tp2) == g.end()) {
        g[tp2] = search(v, tp2.first, tp2.second);
    }
    auto tp3 = make_pair(hour + 2, capacity);
    if (g.find(tp3) == g.end()) {
        g[tp3] = search(v, tp3.first, tp3.second);
    }
    ans += max(g[tp1], max(g[tp2], g[tp3]));
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, search(v, i, m));
    }
    printf("%d", ans);
}