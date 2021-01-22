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

int n,m;

void solve() {
    int id = 0;
    map<string, int> m1;
    map<int, string> m2;
    vector<string> ss(n);
    int arr[11];
    for(int i=0; i<n; ++i){
        cin >> ss[i];
    }

    sort(ss.begin(), ss.end());
    for (int i=0; i<n; ++i) {
        string s=ss[i];
        if (!m1.count(s)) {
            m1[s]=id;
            m2[id++]=s;
        }
        arr[i]=m1[s];
    }

    cin>>m;
    vector<set<int>> v(n+1);
    for (int i=0; i<m; ++i){
        string s1,s2;
        cin >> s1>>s2;
        int i1=m1[s1], i2=m1[s2];
        v[i1].insert(i2);
        v[i2].insert(i1);
    }

    do {
        bool check=true;
        for(int i=0;i+1<n;++i){ 
            if(v[arr[i]].count(arr[i+1])){
                check=false;
                break;
            }
        }
        if(check) {
            for(int i=0; i<n; ++i) {
                cout << m2[arr[i]];
                if(i<n-1) cout<<' ';
            }
            cout << '\n';
            return;
        }
    } while (next_permutation(arr,arr+n));

    cout << "You all need therapy.\n";
}

int main() {
    fast();
    while (cin >> n) {
        solve();
    }

    return 0;
}
