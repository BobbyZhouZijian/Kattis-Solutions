#include <iostream>
#include <vector>
using namespace std;

vector<int> f;

int find(int x) {
    if (f[x] == -1) return x;
    f[x] = find(f[x]);
    return f[x];
}

void join(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        f[fy] = fx;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    f.resize(k, -1);
    vector<vector<int>> v(n, vector<int>(m));
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m ; ++ j) {
            cin >> c;
            v[i][j] = c - 'A';
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i == 0) continue;
            join(v[i][j], v[i-1][j]);
        }
    }

    int res = 0;
    for (int i : f) if (i == -1) res++;
    cout << res << endl;
}