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

int N,M;

void solve() {
    vector<int> arr;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        arr.push_back(x);
    }
    vector<int> v;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i+1; j < arr.size();++j){
            v.push_back(arr[i]+arr[j]);
        }
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int q; cin >> q;
        cout << "Closest sum to " << q << " is ";
        auto p = lower_bound(v.begin(), v.end(), q);
        if (p==v.begin()) cout << *p;
        else if (p==v.end()) cout << *(p-1);
        else {
            int d1 = q-*(p-1), d2=*p-q;
            if (d1<d2) cout << *(p-1);
            else cout << *p;
        }
        cout << ".\n";
    }
}

int main() {
    fast();

    int cnt = 1;
    while (cin >> N) {
        cout << "Case " << cnt++ << ":\n";
        solve();
    }


    return 0;
}
