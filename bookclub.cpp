#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;
vector<bool> checked;
vector<int> l, r;

int dfs(int x) {
    for (int nb : G[x]) {
        if (!checked[nb]) {
            checked[nb] = true;
            if (r[nb] == -1 || dfs(r[nb])) {
                l[x] = nb;
                r[nb] = x;
                return 1;
            }
        }
    }
    return 0;
}

int hungarian() {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (l[i] == -1) {
            checked.clear();
            checked.resize(N, false);
            dfs(i);
        }
    }
    for (int i : l) ans += (i != -1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    G.resize(N);
    l.resize(N, -1);
    r.resize(N, -1);

    int u, v;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
    }

    int res = hungarian();
    // cout << res << endl;
    if (res == N) cout << "YES" << endl;
    else cout << "NO" << endl;
}