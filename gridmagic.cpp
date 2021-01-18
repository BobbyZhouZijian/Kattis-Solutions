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

vector<int> nums1;
unordered_set<int> nums2;
int powers[9];

bool is_prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i < sqrt(x) + 1e-9; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

void initialize() {
    powers[0] = 1;
    for (int i = 1; i < 9; ++i) powers[i] = powers[i-1]*10;
    vector<int> v {0};
    for (int i = 1; i <= n; ++i) {
        vector<int> v1;
        for (int t : v) {
            for (int k = 1; k <= 9; k++) {
                int nxt = 10*t+k;
                if (is_prime(nxt)) {
                    v1.push_back(nxt); 
                }
            }
        }
        v = v1;
        if (i == m) {
            for (int num : v1) nums2.insert(num);
        }
    }
    nums1 = v;
}

vector<int> cur;

int ans = 0;

void dfs(int x) {
    if (x == m) {
        bool can = true;
        for (int i = 0; i < n; ++i) {
            int num = 0;
            for (int k : cur) {
                num *= 10;
                num += ((k % powers[n-i]) / powers[n-i-1]);
            }
            if (nums2.find(num) == nums2.end()) {
                can = false;
                break;
            }
        }
        if (can) ans++;
        return;
    }
    for (int i = 0; i < nums1.size(); ++i) {
        cur.push_back(nums1[i]);
        dfs(x+1);
        cur.pop_back();
    }
}

int main() {
    fast();
    cin >> n >> m;
    if (n < m) swap(n,m);
    initialize();
    dfs(0);
    cout << ans << endl;

    return 0;
}
