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

void solve() {
    vector<int> v;
    int x;
    int lo = 0, hi = 0;
    unordered_map<int, int> oc;
    unordered_set<int> seen;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        v.push_back(x);
        oc[x] = i;
        seen.insert(x);
        hi = max(hi, x);
    }

    for (int i = 0; i < N; ++i) {
        cin >> x;
        v.push_back(x);
        if (seen.find(x) != seen.end())
            lo = max(lo, x);
        oc[x] = i + N;
        hi = max(hi, x);
    }

    for (int k =0; k < 30; ++k) {
        int mid = (lo+hi)/2;
        bool can = true;
        for (int i = 0; i < 2*N; ++i) {
            int cur = v[i];
            if (oc[cur]==i || cur <= mid) continue;
            int j = i+1;
            while(j<2*N && v[j]<=mid)++j;
            if (j<2*N && cur != v[j]) {
                can = false;
                break;
            }
            i = j;
        }

        if (can) hi = mid;
        else lo = mid;
    }

    cout << hi << endl;
}

int main() {
    fast();
    cin >> N;
    solve();

    return 0;
}
