#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPL(i,j, n) for (int i = j; i < n; ++i)
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
void fast() {
   //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    map<ii, int> warr;
    for (int i = 0; i < n; ++i) {
        int p,s;
        cin>>p>>s;
        warr.insert({{s,p}, i});
    }
    vi prevarr(n, -1);
    map<int, int> s;
    auto it = warr.begin();
    s.insert({(it->first).second, it -> second});
    warr.erase(warr.begin());
    for (auto it = warr.begin(); it != warr.end();++it) {
        int u = (it->first).second;
        int ind = it->second;
        auto it2 = s.upper_bound(u);
        if (it2== s.begin()) {
            s.insert({u, ind});
        } else {
            int prevind = prev(it2)->second;
            prevarr[ind] = prevind;
            s.erase(prev(it2));
            s.insert({u, ind});
        }
    }
    vi ans(n);
    int cur = 1;

    for (auto &[u, ind]: s) {
       int cur2 = ind;
        while (cur2 != -1) {
            ans[cur2] = cur;
            cur2 = prevarr[cur2];
        }
        cur++;
    }
    REP(i, n) {
        cout<<ans[i]<<" ";
    }
}



int main() {
    fast();


    return 0;
}
