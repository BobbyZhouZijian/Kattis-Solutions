#include <bits/stdc++.h>
using namespace std;

int r,c,n;
int arr[505][505];

struct Node {
    int c, n, i, j;

    bool operator<(const Node & other) const {
        return  c > other.c;
    }
};


int ispass(int x, int y) {
    if (x < 1 || x > r-2 || y < 1 || y > c-2) return 0;
    if (arr[x-1][y] == -1 || arr[x+1][y] == -1 || arr[x][y-1] == -1 || arr[x][y+1] == -1 || arr[x][y] == -1) return 0;
    if (arr[x-1][y] <= arr[x][y] || arr[x+1][y] <= arr[x][y]) return 0;
    if (arr[x][y-1] >= arr[x][y] || arr[x][y+1] >= arr[x][y]) return 0;
    return 1;
}

int dx[] = {1,0,-1}, dy[] = {1,1,1};

int main() {
    scanf("%d%d%d",&r,&c,&n);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%d", &arr[i][j]);  
        }
    }
    for(int i = 0; i < r; ++i) arr[i][c] = 0;

    priority_queue<Node> q;
    for (int i = 0; i < r; ++i) {
        if (arr[i][0] == -1) continue;
        q.push({arr[i][0], 0, i, 0});
    }

    vector<vector<vector<int>>> dist(r+1, vector<vector<int>>(c+1, vector<int>(n+1,-1)));

    bool work = false;
    while (!q.empty()) {
        auto [cost, k, x, y] = q.top(); q.pop();
        if (dist[x][y][k] != -1) continue;
        dist[x][y][k] = cost;
        if (k == n && y == c) {
            work = true;
            printf("%d\n", cost);
            break;
        }

        for (int l = 0; l < 3; ++l) {
            int nx = x + dx[l], ny = y + dy[l];
            if (nx < 0 || nx >= r || ny < 0 || ny > c || arr[nx][ny] == -1) continue;
            int n1 = k + (ispass(nx,ny));
            int c1 = cost + arr[nx][ny];
            if (n1 > n || dist[nx][ny][n1] != -1) continue;
            q.push({c1, n1, nx, ny});
        }
    }

    if (!work) printf("impossible\n");
}
