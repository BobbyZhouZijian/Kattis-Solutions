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

int r, c;

void solve() {
    vector<vector<char>> v(r, vector<char>(c));
    for (int i = 0; i<r; ++i) {
        for (int j = 0; j <c; ++j) {
            cin >> v[i][j];
        }
    }
    string s;
    cin >> s;
    s += "*";

    vector<vector<vector<int>>> vis(r, vector<vector<int>>(c, vector<int>(s.size()+1, INT_MAX/2)));
    queue<tuple<int, int, int>> q;
    q.push({0,0,0});
    vis[0][0][0]=0;

    int ans = INT_MAX;

    while (!q.empty()) {
        int i,j,l;
        tie(i,j,l) = q.front(); q.pop();

        if (l == s.length()) {
            ans = vis[i][j][l];
            break;
        }

        if (v[i][j]==s[l]) {
            if (vis[i][j][l+1]>vis[i][j][l]+1) {
                vis[i][j][l+1] = vis[i][j][l]+1;
                q.push({i,j,l+1});
            }
        }

        int nexti = i, nextj = j; 

        while (nexti>=0 && v[i][j]==v[nexti][j]) nexti--;
        if (nexti>=0 && vis[nexti][j][l]>vis[i][j][l]+1) {
            vis[nexti][j][l] = vis[i][j][l]+1;
            q.push({nexti,j,l});
        }

        nexti = i;
        while (nexti < r && v[nexti][j]==v[i][j]) nexti++;
        if (nexti < r && vis[nexti][j][l]>vis[i][j][l]+1) {
            vis[nexti][j][l] = vis[i][j][l]+1;
            q.push({nexti,j,l});
        }

        while (nextj>=0 && v[i][j] == v[i][nextj]) nextj--;
        if (nextj>=0 && vis[i][nextj][l] > vis[i][j][l]+1) {
            vis[i][nextj][l] = vis[i][j][l] + 1;
            q.push({i, nextj, l});
        }

        nextj = j;
        while (nextj < c && v[i][j] == v[i][nextj]) nextj++;
        if (nextj < c && vis[i][nextj][l] > vis[i][j][l]+1) {
            vis[i][nextj][l] = vis[i][j][l] + 1;
            q.push({i, nextj, l});
        }
    }

    cout << ans << endl;
}

int main() {
    fast();
    cin >> r >> c;
    solve();

    return 0;
}
