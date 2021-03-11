#include <bits/stdc++.h>
using namespace std;

int n;
int g[35][35], match[35];
bool vis[35];
vector<vector<int>> AL;

int aug( int L ) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (auto &R : AL[L]) {
        if (match[R] == -1 || aug(match[R])) {
            match[R] = L;
            return 1;
        }
    }
    return 0;
}

bool work(int k) {
    AL.assign(n+1, {});
    memset(match, -1, sizeof match);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] >= k) {
                AL[i].push_back(j);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        memset(vis, 0, sizeof vis);
        res += aug(i);
    }

    return res == n;
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    cin >> n;
    int hi = 1000000, lo = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    int ans = 0;
    for (int k = 0; k < 50 && lo < hi; ++k) {
        int mid = (lo + hi) / 2; 
        if (work(mid)) {
            ans = max(ans, mid);
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    cout << ans << '\n';
}
