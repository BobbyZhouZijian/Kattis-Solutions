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



int main() {
    fast();
    int n; cin >> n;

    if (n==0) {
        cout << "0 0" << endl;
        return 0;
    }
    int i = 1;
    for (; i*i<=n; ++i) {
        if (n % i !=0) continue;
        int j = n / i;
        if ((i+j)%2==1) continue;
        cout << (j-i)/2 << ' ' << (i+j)/2 << endl;
        return 0;
    }

    cout << "impossible" << endl;

    return 0;
}
