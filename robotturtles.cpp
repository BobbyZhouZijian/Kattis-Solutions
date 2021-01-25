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

char g[10][10];

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int main() {
    fast();
    for (int i =0; i < 8; ++i) {
        for (int j = 0; j<8; ++j) {
            char c; cin >> c;
            g[i][j] = c;
        }
    }

    queue<tuple<string, int, int, int>> q;
    q.push({"", 0, 7*8, 1});

    bool seen[10][10] = {0};

    while (!q.empty()) {
        string s;
        int dir, loc, mask;
        tie(s, dir, loc, mask) = q.front(); q.pop();

        int x = loc / 8, y = loc % 8;
        if (g[x][y] == 'D') {
            cout << s << endl;
            return 0;
        }
        seen[x][y] = 1;

        int left = (dir+1)%4;
        if ((mask & (1<<left)) == 0)
            q.push({s+'L', left, loc, mask | (1<<left)});

        int right = (dir+3)%4;
        if ((mask & (1<<right)) ==0)
            q.push({s+'R', right, loc, mask | (1<<right)});
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && g[nx][ny] != 'C' && !seen[nx][ny]) {
            if (g[nx][ny] == 'I')
                q.push({s+"XF", dir, nx*8+ny, (1 << dir)});
            else
                q.push({s+'F', dir, nx*8+ny, (1 << dir)});
        }
    }

    cout << "no solution" << endl;

    return 0;
}
