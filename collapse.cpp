#include <bits/stdc++.h>
using namespace std;

int N;
int m[100001];
int s[100001];
vector<vector<pair<int, int>>> g;


void solve() {
    for (int i = 0; i < N; ++i) {
        int k, t;
        cin >> k >> t;
        while (t--) {
            int x, y;
            cin >> x >> y;
            x--;
            s[i] += y;
            g[x].push_back({i, y});
        }
        s[i] -= k;
    }

    queue<int> q;
    q.push(0);
    s[0] = -1;

    int ans = 0;
    while (!q.empty()) {
        int d = q.front(); q.pop();
        ans++;
        for (auto p: g[d]) {
            int i = p.first, val = p.second;
            // cout << i << " " << s[i] << endl;
            if (s[i] < 0) continue;
            s[i] -= val;
            if (s[i] < 0) {
                q.push(i);
            }
        }
    }
    cout << N - ans << endl;
}

int main() {
    cin >> N;
    memset(m, 0, N * sizeof(m[0]));
    memset(s, 0, N * sizeof(s[0]));
    g.resize(N);
    solve();
}