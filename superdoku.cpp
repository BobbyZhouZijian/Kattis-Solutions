#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int n, m;
int match[105];
bool vis[105], visc[105][105];
vector<vector<int>> res;


int Aug(int L) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (int R = 1; R <= n; ++R) {
        if (visc[L][R]) continue;
        if (match[R] == -1 || Aug(match[R])) {
            match[R] = L;
            return 1;
        }
    }
    return 0;
}

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    memset(visc, 0, sizeof visc);
    cin >> n >> m;

    res.resize(n, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        memset(vis,0,sizeof vis); 
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            res[i][j] = x;
            if (vis[x] || visc[j][x]) {
                cout << "no\n";
                return 0;
            }
            vis[x] = 1;
            visc[j][x] = 1;
        }
    }

    for (int i = m; i < n; ++i) {
        memset(match,-1,sizeof match);
        for (int j = 0; j < n; ++j) {
            memset(vis, 0, sizeof vis);
            Aug(j);
        }
        for (int k = 1; k <= n; ++k) {
            int col = match[k];
            res[i][col] = k;
            visc[col][k] = 1;
        }
    }

    cout << "yes\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j] << ' ';
        }
        cout << "\n";
    }

}
