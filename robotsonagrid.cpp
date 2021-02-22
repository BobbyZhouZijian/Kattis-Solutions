#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
char grid[1005][1005];
ll dp[1005][1005];
ll mod = (1ll << 31) - 1;
bool vis[1005][1005];

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool dfs(int x, int y) {
    if (x == n && y == n) return true;
    if (vis[x][y]) return false;
    vis[x][y] = 1;
    bool ok = false;

    for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 1 || nx > n || ny < 1 || ny > n || grid[nx][ny] == '#') continue;
        ok = ok || dfs(nx, ny);
    }

    return ok;
}

int main() {
    memset(dp, 0, sizeof dp);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf(" %c", &grid[i][j]);

    for (int i = 1; i <= n; ++i) {
        if (grid[1][i] != '#') dp[1][i] = 1;
        else break;
    }

    for (int i = 1; i <= n; ++i) {
        if (grid[i][1] != '#') dp[i][1] = 1;
        else break;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            if (grid[i][j] != '#')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }

    if (dp[n][n]) printf("%lld\n", dp[n][n]);
    else {
        memset(vis, 0, sizeof vis);
        if (dfs(1, 1)) printf("THE GAME IS A LIE\n");
        else printf("INCONCEIVABLE\n");
    }
}
