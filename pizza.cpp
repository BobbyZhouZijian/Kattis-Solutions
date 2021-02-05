#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int TC,x,y;
int arr[MAXN][MAXN];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int calc(int a, int b) {
    int ans = 0;
    for (int i = 0; i < x; ++i ) {
        for (int j = 0; j < y; ++j) {
            ans += arr[i][j] * (abs(a-i) + abs(j-b));
        }
    }
    return ans;
}

void solve() {
    cin >> y >> x;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> arr[i][j];
        }
    }

    int i = 0, j = 0;
    int cur = calc(i,j);
    bool can = true;
    while (can) {
        can = false;
        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k], ny = j + dy[k];
            if (nx<0 || nx >= x || ny < 0 || ny >= y) continue;
            int next = calc(nx, ny);
            if (next < cur) {
                can = true;
                cur = next;
                i = nx;
                j = ny;
            }
        }
    }

    cout << cur << " blocks\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> TC;
    while (TC--)
        solve();
}
