#include <bits/stdc++.h>
using namespace std;

int n, m;
bitset<101> bs;
vector<vector<int>> g;

void dfs(int x, bitset<101> &bs) {
    int cur = bs[x];
    bs.flip(x);
    for (int r : g[x]) {
        if (bs[r] == cur)
            dfs(r, bs);
    }
}

int test(int i, bitset<101> &bs) {
    int count = 0;
    while (bs.count() != 0 && bs.count() != n) {
        dfs(i, bs);
        count++;
    }
    return count;
}

int main() {
    bs.reset();
    cin >> n >> m;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x) bs.set(i);
    }

    g.assign(n+1,{});
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    int res = n;
    for (int i = 0; i < n; ++i) {
        bitset<101> cur = bs;
        res = min(res, test(i, cur));
    }

    cout << res << endl;
}
