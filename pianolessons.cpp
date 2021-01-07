#include <bits/stdc++.h>
using namespace std;

int N, M;

bool v[1001][1001];
int l[1001], r[1001];
bool vis[1001];

bool dfs(int i) {
    for (int j = 0; j < M; ++j) {
        if (v[i][j] && !vis[j]) {
            vis[j] = true;
            if (r[j] == -1 || dfs(r[j])) {
                l[i] = j;
                r[j] = i;
                return true;
            }
        }
    }
    return false;
}

int bipartite() {
    memset(l, -1, N * sizeof(l[0]));
    memset(r, -1, M * sizeof(r[0]));
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (l[i] == -1) {
            memset(vis, 0, M * sizeof(vis[0]));
            ans += dfs(i);
        } else {
            ans++;
        }
    }
    return ans;
}

void solve() {
    memset(v, 0, sizeof(v));
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        for (int j = 0; j < x; ++j) {
            int y; cin >> y;
            y--;
            v[i][y] = 1;
        }
    }
    cout << bipartite() << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    solve();
}