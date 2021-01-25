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

int N;

int main() {
    fast();
    cin >> N;
    ost<pair<int,int>> t;
    for (int i = 1; i <= N; ++i) {
        int x; cin>>x;
        t.insert({i,x});
    }

    int caller = 0;
    while (N>1) {
        int x = (t.find_by_order(caller))->second;
        int order = (caller+x) % N;
        if (order == 0) order = N;
        t.erase(t.find_by_order(order-1)); 
        caller = order;
        if (caller == N) caller = 0;
        else caller--;
        N--;
    }

    cout << (t.find_by_order(0))->first << endl;

    return 0;
}
