#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> match;
vector<bool> vis;
vector<vector<int>> v;
vector<pair<int,int>> edges;

int aug(int L) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (auto &R : v[L]) {
        if (match[R] == -1 || aug(match[R])) {
            match[R] = L;
            return 1;
        }
    }
    return 0;
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    cin >> n;
    match.assign(n+1, -1);
    vis.assign(n+1,false);
    v.resize(n+1);
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        edges.push_back({a,b});
        v[a].push_back(i);
        v[b].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        vis.assign(n+1,false);
        aug(i);
    }

    for (int i = 0; i < n; ++i){
        auto [a,b] = edges[i];
        int builder = match[i];
        if (builder == a) {
            cout << a << ' ' << b << '\n';
        } else {
            cout << b << ' ' << a << '\n';
        }
    }
}
