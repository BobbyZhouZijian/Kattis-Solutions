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

struct node {
    int depth=0;
    node* child[26];
};

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int R,C;

void solve() {
    vector<vector<char>> v(R+1,vector<char>(C+1));
    for (int i = 0; i < R; ++i) {
        for (int j =0; j < C; ++j) {
            char c; cin >> c;
            v[i][j] = c;
        }
    }

    node* root = new node;

    int maxm = 0;

    for (int j = 0; j < C; ++j) {
        node* travel = root;
        for (int i = R-1; i>=0; --i) {
            int val = v[i][j] - 'a';
            if (travel->child[val] == nullptr) {
                node* next = new node;
                next->depth = travel->depth+1;
                travel->child[val] = next;
            } else {
                maxm = max(maxm, travel->depth+1);
            }
            travel = travel->child[val];
        }
    }

    cout << R - maxm - 1 << endl;
}

int main() {
    fast();
    cin >> R >> C;

    solve();


    return 0;
}
