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


int main() {
    fast();
    string s;
    getline(cin, s);
    int cnt=1;
    for (char c : s) if (c==' ')cnt++;

    int n; cin>>n;
    vector<string>v(n);
    vector<bool> seen(n,false);
    for(int i=0; i<n; ++i){
        string s; cin>>s;
        v[i]=s;
    }

    vector<int> v1,v2;
    int j=-1,t=0;
    for(int i=0; i<n; ++i, t=1-t){
        for(int k=0; k<cnt; ++k){
            ++j;
            for(;;++j) {
                j%=n;
                if(!seen[j]) break;
            }
        }
        if(!t) v1.push_back(j);
        else v2.push_back(j);
        seen[j]=1;
    }
    cout << v1.size() << '\n';
    for(int i=0; i<v1.size(); ++i){
        cout << v[v1[i]] << '\n';
    }
    cout << v2.size() << '\n';
    for (int i=0; i<v2.size(); ++i){
        cout << v[v2[i]] << '\n';
    }

    return 0;
}
