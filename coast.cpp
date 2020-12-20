#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt = 0;
vector<vector<char>> v;
vector<vector<bool>> vis;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j])
        return;
    vis[i][j] = true;
    for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj]) continue;
        if (v[ni][nj] == '1') {
            cnt++;
        } else {
            dfs(ni, nj);
        }
    } 
}

int main() {
    cin >> n >> m;
    v.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (v[i][0] == '0')
            dfs(i, 0);
        else
            cnt++;
        if (v[i][m - 1] == '0')
            dfs(i, m - 1);
        else
            cnt++;
    }

    for (int j = 0; j < m; ++j) {
        if (v[0][j] == '0')
            dfs(0, j);
        else
            cnt++;
        if (v[n - 1][j] == '0')
            dfs(n - 1, j); 
        else
            cnt++;
    }
    cout << cnt << endl;
}