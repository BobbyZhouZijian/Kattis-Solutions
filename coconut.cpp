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

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).


void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int t, k;

int main() {
    fast();
    cin >> k >> t;

    ost<pair<int,int>> tree;

    for (int i = 1; i <= t; ++i) {
        tree.insert({i*2, 2});
    }

    int cur = 0;
    while (tree.size()>1) {
        cur = (cur + k-1) % (tree.size());
        auto p = tree.find_by_order(cur);
        int life = p->second;
        int idx = p->first;
        if (life==2) {
            tree.erase(p);
            tree.insert({idx,1});
            tree.insert({idx+1,1});
        } else if (life==1) {
            tree.erase(p);
            tree.insert({idx, 0});
            cur++;
        } else {
            tree.erase(p); 
        }
    }

    cout << (tree.find_by_order(0))->first / 2 << endl;

    return 0;
}
