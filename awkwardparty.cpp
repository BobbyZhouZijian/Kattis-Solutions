#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        m[l].push_back(i); 
    }
    int minm = n;
    for (auto it : m) {
        vector<int> &v = it.second;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; ++i) {
            minm = min(minm, v[i + 1] - v[i]);
        }
    }
    cout << minm;
}