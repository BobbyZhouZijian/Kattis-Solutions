#include <bits/stdc++.h>
using namespace std;

char grid[4][4]; 
bool vis[4][4];

int cnt = 0;
bool flag = 0;

int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

bool check(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void dfs(int x, int y, char ch) {
    cnt++;
    vis[x][y] = 1;
    if (cnt == 16) {
        flag = 1; 
        return;
    }

    for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k]; 
        if (!vis[nx][ny] && check(nx,ny)) {
            if (grid[nx][ny] == ch) {
                vis[nx][ny] = 1;
                cnt++;
                if (cnt == 16) {
                    flag = 1;
                    return;
                }

                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        if (!vis[i][j] && grid[i][j] != 'W' && grid[i][j] != ch) {
                            dfs(i,j,grid[i][j]);
                            break;
                        }
                    }
                }
                vis[nx][ny] = 0;
                cnt--;
            } else if (grid[nx][ny] == 'W') {
                dfs(nx, ny, ch);
            }
        }
    }

    vis[x][y] = 0;
    cnt--;
}

int main() {
    memset(vis,0,sizeof vis);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] != 'W') {
                dfs(i,j,grid[i][j]);
                break;
            }
        }
    }

    if (flag) {
        cout << "solvable\n";
    } else {
        cout << "not solvable\n";
    }
}
