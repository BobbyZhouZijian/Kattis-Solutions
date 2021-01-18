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

int TC, N;

void solve() {
    queue<int> q;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        q.push(i); 
    }
    for (int i = 1; i <= N; ++i) {
        for (int k = 0; k < i; ++k) {
            int x = q.front(); q.pop();
            q.push(x);
        }
        int x = q.front();
        nums[x] = i;
        q.pop();
    }
    for (int x : nums) cout << x << " ";
    cout << "\n";
}

int main() {
    fast();
    cin >> TC;
    while (TC--) {
        cin >> N;
        solve();
    }

    return 0;
}
