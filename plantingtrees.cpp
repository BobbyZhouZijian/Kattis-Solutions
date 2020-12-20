#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.rbegin(), v.rend());
    int d = 0;
    for (int i = 0; i < n; ++i) {
        d = max(d, i + v[i] + 1);
    }
    cout << d + 1 << endl;
}