#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
ll INF = (ll)1e14;

void solve() {
    map<string, int> m1;
    int id = 0;

    string s;
    for (int i = 0 ; i< N; ++i) {
        cin >> s;
        if (!m1.count(s)) {
            m1[s] = id;
            id++;
        }
    }
    m1["English"] = id;
    string s1, s2;
    ll cost;
    vector<vector<pair<ll, int>>> g(N + 1);
    for (int i = 0 ; i < M; ++i) {
        cin >> s1 >> s2 >> cost;
        int d1 = m1[s1], d2 = m1[s2];
        g[d1].push_back({cost, d2});
        g[d2].push_back({cost, d1});
    }

    int source = m1["English"];

    queue<int> q;
    vector<bool> vis(N + 1, false);
    vector<ll> dist(N + 1, INF);
    vector<int> len(N + 1, 99999999);
    dist[source] = 0;
    len[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int p = q.front(); q.pop();
        if (vis[p]) continue;
        vis[p] = true;
        int cur_l = len[p];
        int cur_d = dist[p];

        for (auto b : g[p]) {
            int j = b.second;
            ll cost = b.first;
            if (len[j] >= cur_l + 1 && dist[j] >= cost) {
                if (len[j] == 99999999) {
                    q.push(j);
                }
                dist[j] = cost;
                len[j] = cur_l + 1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (dist[i] == INF) {
            cout << "Impossible" << endl;
            return;
        }
    }
    ll ans = 0;
    for (ll i : dist) ans += i;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    solve();
}