#include <iostream>
#include <vector>
using namespace std;

int main() {
    int inf = 1 << 28;
    while (cin) {
        int n, m, q;
        cin >> n >> m >> q;

        if (n == 0 && m == 0 && q == 0)
            break;

        vector< vector<int> > g(n, vector<int>(n, inf));
        for (int i = 0; i < n; i++) {
            g[i][i] = 0;
        }

        for (int i = 0; i < m; ++ i) {
            int x, y, w;
            cin >> x >> y >> w;
            g[x][y] = min(w, g[x][y]);
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (g[i][k] < inf && g[k][j] < inf)
                        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; g[i][j] != -inf && k < n; ++k) {
                    if (g[k][k] < 0 && g[i][k] != inf && g[k][j] != inf)
                        g[i][j] = -inf;
                }
            }
        }
        for (int i = 0; i < q; ++i) {
            int x, y;
            cin >> x >> y;

            if (g[x][y] == inf)
                cout << "Impossible" << endl;
            else if (g[x][y] == -inf)
                cout << "-Infinity" << endl;
            else
                cout << g[x][y] << endl;
        }
        cout << endl;
    }
}
