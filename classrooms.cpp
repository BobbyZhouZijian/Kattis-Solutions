#include <bits/stdc++.h>
using namespace std;

int n, k;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    cin >> n >> k;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }

    sort(arr.begin(), arr.end(), [](pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    });
    int ans = 0;

    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        auto it = s.lower_bound(-arr[i].first);
        if (it == s.end()) {
            if (s.size() < k) {
                s.insert(-arr[i].second-1);
                ans++;
            }
        } else {
            s.erase(it);
            s.insert(-arr[i].second-1);
            ans++;
        }
    }

    cout << ans << '\n';
}
