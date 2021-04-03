#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

unordered_map<int, vector<int>> rows;
unordered_map<int, vector<int>> cols;

int main() {
    cin >> n;

    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        rows[x].push_back(y);
        cols[y].push_back(x);
    }

    ll res = 0;
    for (auto &[x, ys] : rows) {
        ll y_num = ys.size() - 1;
        for (int &y : ys) {
            ll x_num = cols[y].size() - 1;
            res += x_num * y_num;   
        }
    }

    cout << res << '\n';
}