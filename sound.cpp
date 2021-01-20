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

int n, m, c;

int main() {
    fast();
    cin >> n >> m >> c;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v.push_back(x);
    }

    deque<int> q,q1;
    for (int i = 0; i < m; ++i) {
        while (!q.empty() && v[q.back()] < v[i]) q.pop_back();
        q.push_back(i);
        while (!q1.empty() && v[q1.back()] > v[i]) q1.pop_back();
        q1.push_back(i);
    }

    vector<int> maxm {v[q.front()]}, minm {v[q1.front()]};

    for (int i = m; i < v.size(); ++i) {
        while (!q.empty() && q.front() <= i - m) q.pop_front();
        while (!q.empty() && v[q.back()] < v[i]) q.pop_back();
        q.push_back(i);
        maxm.push_back(v[q.front()]);
        while (!q1.empty() && q1.front() <= i - m) q1.pop_front();
        while (!q1.empty() && v[q1.back()] > v[i]) q1.pop_back();
        q1.push_back(i);
        minm.push_back(v[q1.front()]);
    }

    bool found = false;
    for (int i = 0; i < maxm.size(); ++i){
        if (maxm[i] - minm[i] <= c) {
            found = true;
            cout << i+1 << "\n";
        }
    }

    if (!found) cout << "NONE\n";

    return 0;
}
