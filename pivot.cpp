#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i ) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    vector<int> minv(n, 100001), maxv(n, 0);
    maxv[0] = v[0];
    minv[n - 1] = v[n - 1];
    for (int i = 1; i < n; ++i) {
        maxv[i] = max(maxv[i - 1], v[i]);
    }
    for (int i = n - 2; i >=0; --i) {
        minv[i] = min(minv[i + 1], v[i]);
    }
    vector<bool> p(n, true);
    for (int i = 0; i < n; ++i) {
        if (maxv[i] != v[i]) p[i] = false;
        if (minv[i] != v[i]) p[i] = false;
    }
    int cnt = 0;
    for (bool b : p) cnt += b;
    cout << cnt;
}