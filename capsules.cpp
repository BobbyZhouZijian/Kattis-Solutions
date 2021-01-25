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

int R, C, N;
int grid[10][10] = {0};
int reg[10][10];
int m[100] = {0};
int sz[100];

bool backtrack(int i) {
    if (i == R*C) return true;
    int x = i / C+1, y = i % C+1;
    if (grid[x][y] != 0) {
        return backtrack(i+1);
    }
    int id = reg[x][y];
    int cur = m[id];
    cur |= (1 << grid[x-1][y]);
    cur |= (1 << grid[x][y-1]);
    cur |= (1 << grid[x+1][y]);
    cur |= (1 << grid[x][y+1]);
    cur |= (1 << grid[x-1][y-1]);
    cur |= (1 << grid[x-1][y+1]);
    cur |= (1 << grid[x+1][y+1]);
    cur |= (1 << grid[x+1][y-1]);

    for (int j = 1; j <= sz[id]; ++j) {
        if (cur & (1 << j)) continue;
        m[id] |= (1 << j);
        grid[x][y] = j;
        if (backtrack(i+1))
            return true;
        m[id] -= (1<<j);
        grid[x][y] = 0;
    }
    return false;
}

int main() {
    fast();
    cin >> R >> C;
    for (int i =1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            char c; cin >> c;
            if (c == '-')
                grid[i][j] = 0;
            else
                grid[i][j] = c-'0';
        }
    }

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int n; cin >> n;
        sz[i] = n;
        for (int j = 0; j < n; ++j) {
            string s; cin >> s;
            int x = s[1] -'0', y = s[3] - '0';
            reg[x][y] = i;
            m[i] |= (1 << grid[x][y]);
        }
    }

    backtrack(0);

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
