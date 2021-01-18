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

int TC;
int K, N;

void solve() {
    cin >> K >> N;
    vector<int> arr {0};
    for (int i = 0 ; i < N; ++i) {
        int j = 0;
        while (j < arr.size() && arr[j]>0)++j;
        if (j<arr.size()) {
            arr[j]=j+1;
        } else {
            arr.push_back(j+1);
        }
        while(j)arr[--j]--;
    }
    cout << K << " " << arr.size() << "\n";
    for (int i = 1; i<=arr.size(); ++i) {
        cout << arr[i-1] << " ";
        if (i%10==0) cout << "\n";
    }
    cout << "\n";
}

int main() {
    fast();
    cin >> TC;
    while (TC--) {
        solve(); 
    }

    return 0;
}
