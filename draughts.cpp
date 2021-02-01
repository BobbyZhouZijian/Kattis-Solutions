#include <bits/stdc++.h>
using namespace std;

int TC;

char board[11][11];
queue<pair<int,int>> whites;

int dx[4] = {-1,-1,1,1};
int dy[4] = {-1,1,1,-1};

int search(int i, int j) {
    int ans = 0;
    for (int k = 0; k < 4; ++k) {
        int nx = i+dx[k], ny = j+dy[k];
        int nnx = nx+dx[k], nny = ny+dy[k];
        if (nnx<0 || nnx>9 || nny<0 || nny>9 || board[nx][ny] != 'B' || board[nnx][nny] != '#')
            continue;
        board[i][j] = '#';
        board[nx][ny] = '#';
        board[nnx][nny] = 'W';
        ans = max(ans, 1 + search(nnx, nny)); 
        board[nnx][nny] = '#';
        board[nx][ny] = 'B';
        board[i][j] = 'W';
    }
    return ans;
}

void solve() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            char c;
            cin >> c;
            board[i][j] = c;
            if (c == 'W')
                whites.push({i,j});
        }
    }
    int ans = 0;
    while(!whites.empty()) {
        auto p = whites.front(); whites.pop();
        ans = max(ans, search(p.first, p.second));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> TC;
    while (TC--)
        solve();
}
