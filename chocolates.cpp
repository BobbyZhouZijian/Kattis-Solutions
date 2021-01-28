#include <bits/stdc++.h>
using namespace std;

int r, c;
int ans = 0;
bool seen[10][10];
bool g[10][10];

int dfs1(int x, int y) {
    if (x < 1 || x > r || y < 1 || y > c || seen[x][y] || !g[x][y]) return 0;
    seen[x][y] = 1;
    return 1 + dfs1(x-1,y) + dfs1(x+1,y) + dfs1(x,y-1) + dfs1(x,y+1);
}

int dfs2(int x, int y) {
    if (x < 0 || x > r+1 || y < 0 || y > c+1 || seen[x][y] || g[x][y]) return 0;
    seen[x][y] = 1;
    return 1 + dfs2(x-1,y) + dfs2(x+1,y) + dfs2(x,y-1) + dfs2(x,y+1)
        + dfs2(x-1,y-1) + dfs2(x-1,y+1) + dfs2(x+1,y-1) + dfs2(x+1,y+1);
}



int main() {
    cin >> r >> c;
    int num = r * c;
    int all = (1 << num) - 1;
    memset(g, 0, sizeof g);
    for (int mask = 1; mask <= all; ++mask) {
        int x0=-1,y0=-1;
        int x1=-1,y1=-1;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (mask & (1 << (i*c+j))) {
                    g[i+1][j+1] = 1;
                    x0 = i+1;
                    y0 = j+1;
                } else {
                    g[i+1][j+1] = 0;
                    x1 = i+1;
                    y1 = j+1;
                }
            }
        }

        int cnt1 = __builtin_popcount(mask);
        memset(seen, 0, sizeof seen);
        if (cnt1 != dfs1(x0,y0)) continue;

        memset(seen, 0, sizeof seen);
        int cnt0 = (r+2) * (c+2) - cnt1;
        if (x1 != -1 && cnt0 != dfs2(x1,y1)) continue;
        ans++;
    }

    cout << ans << endl;
}
