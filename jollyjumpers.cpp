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
    while (cin >> N) {
        vector<bool> seen(N+1,false);
        int cur; cin >> cur;
        bool can = true;
        for (int i = 1; i < N; ++i) {
            int nxt; cin >> nxt;
            int diff = abs(nxt - cur);
            if (diff>0 && diff<N && !seen[diff]) {
                seen[diff]=true;
            } else {
                can = false;
            }
            cur=nxt;
        }
        if (can) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }



    return 0;
}
