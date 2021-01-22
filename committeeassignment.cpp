#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

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

bool intersect(set<int> &a, set<int> &b) {
    auto pa = a.begin(), pb = b.begin();
    while (pa != a.end() && pb != b.end()) {
        if (*pa < *pb) pa++;
        else if (*pa > *pb) pb++;
        else return true;
    }
    return false;
}

int ans = INT_MAX;
vector<set<int>> assign;
vector<set<int>> hate;

void dfs(int x, int num) {
    if (num >= ans) return;
    if (x == n) {
        ans = min(num, ans);
        return;
    }
    int len = assign.size();
    for (int i = 0; i < len; ++i) {
        if (!intersect(assign[i], hate[x])) {
            assign[i].insert(x);
            dfs(x+1, num);
            assign[i].erase(x);
        }
    }
    if (num < ans) {
        assign.push_back({x});
        dfs(x+1, num + 1);
        assign.pop_back();
    }
}

void solve() {
    ans = n;
    map<string, int> m1;
    assign.clear();
    hate.clear();
    hate.resize(n);
    int id = 0;
    string s1, s2;
    for (int i = 0; i < m; ++i) {
        cin >> s1 >> s2;
        if (!m1.count(s1)) {
            m1[s1] = id++;
        }
        if (!m1.count(s2)) {
            m1[s2] = id++;
        }
        
        hate[m1[s1]].insert(m1[s2]);
        hate[m1[s2]].insert(m1[s1]);
    }
    dfs(0, 0);

    cout << ans << "\n";
}

int main() {
    fast();
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        solve();
    }

    return 0;
}
