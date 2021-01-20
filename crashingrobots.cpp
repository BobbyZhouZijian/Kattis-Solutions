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

int TC;
int A, B;
int N, M;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int to_digit(char c) {
    int z;
    if (c == 'E') z = 0;
    if (c == 'N') z = 1;
    if (c == 'W') z = 2;
    if (c == 'S') z = 3;
    return z;
}

void solve() {
    cin >> A >> B;
    cin >> N >> M;
    vector<vector<int>> grid(A+1,vector<int>(B+1,-1));
    vector<vector<int>> robots;
    for (int i = 0; i < N; ++i) {
        int x, y,z; char c;
        cin >>x >> y >> c;
        z = to_digit(c);
        robots.push_back({x,y,z});
        grid[x][y]=i;
    }

    bool can = true;

    for (int i = 0; i < M; ++i) {
        int id, rep; char c;
        cin >> id >> c >> rep;
        if (!can) continue;
        id--;
        int x = robots[id][0], y = robots[id][1], z = robots[id][2];
        if (c == 'L') {
            z = (z+rep) % 4;
            robots[id][2] = z;
        }
        else if (c == 'R') {
            z = (z+3*rep) % 4;
            robots[id][2] = z;
        }
        else if (c == 'F') {
            int nx = x, ny = y;
            for (int i = 0; i < rep; ++i) {
                grid[nx][ny] = -1;
                nx += dx[z]; ny += dy[z];
                if (nx > A || nx <= 0 || ny > B || ny <= 0) {
                    cout << "Robot " << id+1 << " crashes into the Wall\n";
                    can = false;
                    break;
                } else if (grid[nx][ny] != -1) {
                    cout << "Robot " << id+1 << " crashes into robot " << grid[nx][ny]+1 << "\n";
                    can = false;
                    break;
                }
                grid[nx][ny] = id;
            }
            robots[id][0] = nx;
            robots[id][1] = ny;
        }
        /*
        cout << "--------------\n";
        for (int i = 0; i < A+1; ++i) {
            for (int j : grid[i]) cout << j << " ";
            cout << "\n";
        }
        cout << "--------------\n";
        */
    }

    if (can) cout << "OK\n";
}

int main() {
    fast();
    cin >> TC;
    while (TC--) {
        solve();
    }

    return 0;
}
