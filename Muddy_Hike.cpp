#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int inf = 1 << 29;
    int r;
    int c;
    cin >> r >> c;
    c+=2;
    vector< vector<int> > memo(r, vector<int>(c, inf));
    vector< vector<int> > map(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c - 1; j++) {
            int cur;
            cin >> cur;
            map[i][j] = cur;
        }
    }

    memo[0][0] = 0;
    set< pair<int, int> > q;
    q.insert(make_pair(0, 0));

    vector<int> dx, dy;
    dx.push_back(0); dx.push_back(0); dx.push_back(-1); dx.push_back(1);
    dy.push_back(1); dy.push_back(-1); dy.push_back(0); dy.push_back(0);

    while (!q.empty()) {
        auto p = *q.begin();
        q.erase(q.begin());
        int rc = p.first;
        int best = p.second;
        int j = rc % c;
        int i = (rc - j) / c;

        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            
            if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                int nextval = max(best, map[nx][ny]);
                if (nextval < memo[nx][ny]) {
                    memo[nx][ny] = nextval;
                    q.insert(make_pair(nx * c + ny, nextval));
                }
            }
        }
    }

    cout << memo[r - 1][c - 1];
    
}