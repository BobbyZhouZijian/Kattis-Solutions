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

int N, B;

void solve() {
    priority_queue<pair<double, int>> pq;
    for (int i = 0; i < N; ++i){
        double x; cin >> x;
        pq.push({x, 1});
    }
    int left = B - N;
    while (left) {
        auto p = pq.top(); pq.pop();
        if (pq.empty()) {
            pq.push({p.first * p.second / (p.second+left), p.second+left});
            break;
        } else {
            double next = pq.top().first;
            int need = (int)ceil(p.first * p.second / next) - p.second;
            int minm = max(1, min(need, left));
            pq.push({p.first * p.second / (p.second+minm), p.second+minm});
            left -= minm;
        }
    }
    cout << (int)ceil(pq.top().first) << endl;
}

int main() {
    fast();
    while (cin >> N >> B) {
        if (N == -1 && B == -1) break;
        solve();
    }

    return 0;
}
