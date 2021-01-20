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
int all = (1 << 9) -1;
unordered_map<int, int> m;

int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

void bfs() {
    queue<pair<int,int>> q;
    q.push({0,all});
    while (!q.empty()) {
        auto [depth, mask] = q.front(); q.pop();
        m[mask] = depth;
        for (int i = 0; i < 9; ++i) {
            int x = i/3, y = i%3;
            int next = mask ^ (1 << i);
            for (int j = 0; j < 4; ++j) {
                int nx = x + dx[j], ny = y + dy[j];
                if (nx>=0 && nx<3 && ny>=0 && ny<3) {
                    next ^= (1 << (nx*3+ny));
                }
            }
            if (!m.count(next))
                q.push({depth+1, next});
        }
    }
}

void solve() {
    int need = all;
    char c;
    for (int i = 0; i < 9; ++i) {
        cin >> c;
        if (c == '*') need ^= (1 << i); 
    }
    cout << m[need] << "\n";
}

int main() {
    fast();
    cin >> TC;
    bfs();
    while (TC--) {
        solve();
    }


    return 0;
}
