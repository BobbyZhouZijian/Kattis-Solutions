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

int n;

int sum;

vector<int> m {0, 1, 2, -1, -1, 5, 9, -1, 8, 6};

vector<int> perms(string s) {
    vector<int> res {stoi(s)};
    reverse(s.begin(), s.end());
    int ans = 0;
    bool can = true;
    for (char c : s) {
        ans *= 10;
        if (m[c-'0'] != -1) {
            ans += m[c-'0'];
        } else {
            can = false;
            break;
        }
    }
    if (can && ans != res.back()) res.push_back(ans);
    return res;
}

int main() {
    fast();
    cin >> n >> sum;

    unordered_set<int> s;
    bool found = false;
    for (int i = 0; i < n; ++i) {
        string a; cin >> a;
        vector<int> perm = perms(a);
        for (int x : perm) {
            int need = sum - x;
            if (s.find(need) != s.end()) {
                found = true;
            }
        }
        for (int x : perm) s.insert(x);
    }

    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
