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

int n, k;

int main() {
    fast();
    cin >> n >> k;

    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    ll left = n;
    priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    for (int i = 0; i < k; ++i) {
        pq.push({v[i], i});
    }

    while (!pq.empty()) {
        auto [time, i] = pq.top(); pq.pop();
        if (time == v[i]) left--;
        if (left-3 <= 0) {
            cout << time << endl;
            break;
        } else {
            left -= 3;
            pq.push({time+2*v[i], i});
        }
    }

    return 0;
}
