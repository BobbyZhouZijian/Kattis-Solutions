#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> m;
    unordered_map<int, int> id;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        m[k]++;
        id[k] = i;
    }
    int o = 0;
    for (auto &it : m) {
        if (it.second > 1) continue;
        o = max(o, it.first);
    }
    if (o == 0) {
        cout << "none" << endl;
    } else {
        cout << id[o] << endl;
    }
}