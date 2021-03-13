#include <bits/stdc++.h>
using namespace std;

int TC;
int c,b;
vector<vector<int>> borders;
int colours[20];

bool dfs(int x, int c, int mask) {
    if (mask & (1 << x)) return true;
    if (colours[x] == 1-c) {
        return false; 
    }
    if (colours[x] == -1) {
        colours[x]  = c;
        for (int k : borders[x]) {
            if (!dfs(k, 1-c, mask))
                return false;
        }
    }
    return true;
}

int test(int mask, int c) {
    // test 1
    bool work1 = 1;
    for (int i = 0; i < c; ++i) {
        if (mask & (1 << i)) continue;
        for (int k : borders[i]) {
            if (!(mask & (1 << k))) {
                work1 = false;
                break;
            }
        }
    }
    if (work1) {
        return 1;
    }

    // test 2 colours
    memset(colours, -1, sizeof colours);
    bool work2 = 1;
    for (int i = 0; i < c; ++i) {
        if (colours[i] == -1) {
            if (!dfs(i,0,mask)) {
                work2 = 0;
                break;
            }
        }
    }

    if (work2) {
        return 2;
    }

    return -1;
}

void solve() {
    cin >> c >> b; 
    borders.assign(c+1,{});
    for (int i = 0; i < b;++i){ 
        int u,v;
        cin >> u >> v;
        borders[u].push_back(v);
        borders[v].push_back(u);
    }

    int t1 = test(0,c);
    if (t1 > 0) {
        cout << t1 << '\n';
        return;
    }

    // find all subsets
    int all = ( 1<<c) - 1;
    int best = 5;
    for (int mask = 1; mask < (1 << c); ++mask) {
        int comp = all ^ mask;
        int t1 = test(mask, c);
        int t2 = test(comp, c);
        if (t1 < 0 || t2 < 0) continue;
        best = min(best, t1 + t2);
    }
    if (best == 5) {
        cout << "many\n";
        return;
    }
    cout << best << '\n';
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    cin >> TC; 
    while (TC--)
        solve();
}
