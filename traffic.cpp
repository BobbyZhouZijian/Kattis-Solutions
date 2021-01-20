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

int x1,x2;

void solve() {
    if (x1>x2) x2+=4;
    else x1+=4;
    unordered_set<int> s1,s2;
    int n1,n2;
    cin >> n1;
    int maxm = 0;
    for (int i = 0; i < n1; ++i) {
        int x; cin >> x;
        s1.insert(x);
        maxm = max(maxm, x);
    }
    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        int x; cin >> x;
        s2.insert(x);
        maxm = max(maxm, x);
    }

    int end = maxm+2;
    bool rest1=true, rest2=true;
    int d1=0, d2=0;
    int i;
    for (i = 1; i <= end; ++i) {
        if (!rest1) d1++; 
        if (!rest2) d2++;
        if (x1+d1==x2+d2) break;
        if (s1.find(i) != s1.end()) {
            rest1=!rest1;
        }
        if (s2.find(i) != s2.end()) {
            rest2=!rest2;
        }
    }
    if (i <= end) {
        cout << "bumper tap at time " << i << endl;
    } else if (!rest1&&rest2&&x1+d1<x2+d2) {
        cout << "bumper tap at time " << end + (x2+d2-x1-d1) << endl;
    } else if (rest1&&!rest2&&x1+d1>x2+d2) {
        cout << "bumper tap at time " << end + (x1+d1-x2-d2) << endl;
    } else {
        cout << "safe and sound" << endl;
    }
}

int main() {
    fast();
    cin >> x1 >> x2;
    solve();

    return 0;
}
