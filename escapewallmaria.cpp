#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

struct HASH {
    size_t operator()(const pair<int,int>&x)const{
        size_t ans=0;
        for(int i=0;i<x.first;i++)
            ans+=x.second;
        return ans;
    }
};

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
      tree_order_statistics_node_update>;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int t, n, m;
char grid[101][101];
int dist[101][101];

string np = "NOT POSSIBLE\n";

vector<pair<int,int> > dirs = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
vector<char> vdirs = {'D', 'U', 'R', 'L'};

void solve() {
    cin >> t >> n >> m;
    queue<pair<int,int> > q;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j]; 
            if (grid[i][j] == 'S') {
                q.push(make_pair(i,j));
                dist[i][j]=0;
            }
        }
    }
    while(!q.empty()) {
        auto node = q.front();
        q.pop();
        int x = node.first, y = node.second;
        if ((x == 0 || x == (n - 1)) || (y == 0 || y == (m - 1))) {
            if (dist[x][y] > t) {
                cout << np;
            } else {
                cout << dist[x][y] << endl;
            }
            return;
        }
        for (int k = 0; k < 4; k++) {
            auto dir = dirs[k];
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (newX < 0 || newX >= n || newY < 0 || newY >= m) {
                continue;
            }
            if (grid[newX][newY] == '0' || grid[newX][newY] == vdirs[k]) {
                if (dist[newX][newY] == -1) {
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push(make_pair(newX, newY));
                }
            }
        }
    }
    cout << np;
}

int main() {
    fast();

    solve();    

    return 0;
}

