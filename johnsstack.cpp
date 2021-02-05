#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int TC;
int n;
int arr[51], ranks[51];

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ranks[i] = arr[i];
    }

    sort(ranks, ranks+n);
    int sz = unique(ranks, ranks+n) - ranks;
    unordered_map<int, int> m, occ;

    for (int i = 0; i < sz; ++i) {
        m[ranks[i]] = i;
        occ[ranks[i]] = 0;
    }

    ll cnt = 0;
    int maxm = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < maxm) {
            cnt++;
            int cur = m[arr[i]];
            ll cum = 0, add = 0;
            for (int j = cur-1; j >= 0; --j) {
                if (occ[ranks[j]] > 0) {
                    add = (cum+1) * occ[ranks[j]];
                    cnt += add;
                    cum += add;
                }
            }
        }
        maxm = max(maxm, arr[i]);
        occ[arr[i]]++;
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> TC;
    while (TC--) {
        solve();
    }
}
