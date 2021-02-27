#include <bits/stdc++.h>
using namespace std;

int r, c, cnt=0;
char g[55][55];

int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

void dfs(int x, int y) {
    if (x < 0 || x > r+1 || y<0 || y>c+1 || g[x][y] == 'V' || g[x][y] == '#') return;
    if (g[x][y] == 'G') cnt++;
    g[x][y] = 'V';

    bool can = true;
    for (int k = 0; k < 4 && can; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if(nx < 0 || nx > r+1 || ny<0 || ny>c+1) continue;
        if (g[nx][ny] == 'T') can = false;
    }

    if (can) {
        dfs(x+1,y);
        dfs(x-1,y);
        dfs(x,y+1);
        dfs(x,y-1);
    }
}

int main() {
    scanf("%d%d", &c, &r);

    int x,y;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            scanf(" %c", &g[i][j]);
            if (g[i][j] == 'P') x = i, y = j;
        }
    } 
    dfs(x,y);
    printf("%d\n", cnt);
}
