#include <iostream>
#include <vector>
#include <set>

using namespace std;

int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m, s;
        cin >> m >> s;
        set<pair<int, int>> g;
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            if (x == 0 && y == 0) continue;
            g.insert({x, y});
        }

        int depth = INF;
        int jBorder = s;
        vector<vector<int>> graph(s + 1, vector<int>(s + 1, INF));
        graph[0][0] = 0;
        for (int i = 0; i <= s; ++i) {
            for (int j = 0; j <= jBorder; ++j) {
                for (auto& p : g) {
                    int prevx = i - p.first, prevy = j - p.second;
                    if (prevx >= 0 && prevy >= 0 && graph[prevx][prevy] < INF && graph[prevx][prevy] + 1 < graph[i][j]) {
                        graph[i][j] = graph[prevx][prevy] + 1;
                        if (i * i + j * j == s * s && graph[i][j] < depth) {
                            depth = graph[i][j];
                            jBorder = j - 1;
                        } else if (i * i + j * j > s * s) {
                            jBorder = j - 1;
                        }
                    }
                }
            }
        }
        if (depth == INF) {
            cout << "not possible" << endl;
        } else {
            cout << depth << endl;
        }
    }
}