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

vector<vector<vector<int>>> patterns(8);
vector<int> board;
int C, P;

void initialize() {
    patterns[1] = {{0},{0,0,0,0}};
    patterns[2] = {{0,0}}; 
    patterns[3] = {{1,0},{0,0,1}};
    patterns[4] = {{1,0,0},{0,1}};
    patterns[5] = {{0,0,0},{1,0},{0,1},{1,0,1}};
    patterns[6] = {{0,0,0},{2,0},{0,1,1},{0,0}};
    patterns[7] = {{0,2},{0,0,0},{1,1,0},{0,0}};
}

int matches(vector<int> &v) {
    
    int res = 0;

    for (int i = 0; i <= C - v.size(); ++i) {
        int lvl = board[i] - v[0];
        bool can = true;
        for (int j = 1; j < v.size(); ++j) {
            if (board[i+j] != lvl + v[j]) {
                can = false;
                break;
            }
        }
        if (can) res++;
    }
    return res;
}

int main() {
    fast();
    initialize();

    cin >> C >> P;

    for (int i = 0; i < C; ++i) {
        int x; cin >> x;
        board.push_back(x);
    }

    int res = 0;

    for (vector<int> &v : patterns[P]) {
        res += matches(v); 
    }

    cout << res << endl;

    return 0;
}
