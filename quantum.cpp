#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int TC;
int l, nop, nw;
int src, sink;
char c;
unordered_map<string, int> m;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int op(int x, string s) {
    for (int i = 0; i < l; ++i) {
        if (s[i] == 'F') x ^= (1 << (l-i-1));
        if (s[i] == 'S') x |= (1 << (l-i-1));
        if (s[i] == 'C') x &= ~(1 << (l-i-1));
    }
    return x;
}

void dijkstra() {
    unordered_map<int, int> dist;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [w, x] = pq.top(); pq.pop();
        if (dist.count(x) && w > dist[x]) continue;
        if (x == sink) {
            cout << w << ' ';
            return;
        }

        for (auto [s, c] : m) {
            int nx = op(x, s);
            int wnx;
            if (dist.count(nx)) wnx = dist[nx];
            else wnx = INF;

            if (w + c < wnx) {
                dist[nx] = w + c;
                pq.push({dist[nx], nx});
            }
        }
    }
    
    cout << "NP ";
}

void solve() {
    m.clear();
    cin >> l >> nop >> nw;
    string s; int cost;
    for (int i = 0; i < nop; ++i) {
        cin >> s >> cost;
        m[s] = cost;
    }

    for (int i = 0; i < nw; ++i) {
        src = 0; sink = 0;
        for (int j = 0; j < l; ++j) {
            cin >> c;
            src <<= 1;
            if (c == '1') src++;
        }
        for (int j = 0; j < l; ++j) {
            cin >> c;
            sink <<= 1;
            if (c == '1') sink++;
        }

        dijkstra();
    }
    cout << '\n';
}

int main() {
    fast();
    cin >> TC;
    while (TC--) solve();
}
