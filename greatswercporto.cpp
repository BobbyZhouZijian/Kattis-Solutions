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
map<char, int> m1;
int assign[30];
int arr[20][20];
int len[20];
int all = (1 << 10) - 1;
int id = 1;
int ans = 0;

bool check() {
    for (int i = 0; i < N; ++i) {
        if (assign[arr[i][0]] == 0) {
            return false;
        }
    }

    int carry = 0;
    for (int j = 0; j < len[N-1]; ++j) {
        int sum = carry;
        for (int i = 0; i < N - 1; ++i) {
            int cur_len = len[i]-1-j;
            if (cur_len < 0) continue;
            int val = assign[arr[i][cur_len]];
            if (val == -1) return true; 
            sum += val;
        }
        int last_val = assign[arr[N-1][len[N-1]-1-j]];
        if (last_val == -1) return true;
        if (sum%10 != last_val) return false;
        carry = sum / 10;
    }
    return carry == 0;
}

void dfs(int x, int used) {
    if (x == id) {
        ans++;
        return;
    }
    int can = all ^ used;
    while (can) {
        int pos = (can & (-can));
        can -= pos;
        int j = __builtin_ctz(pos);
        
        assign[x] = j;
        if (check()) {
            dfs(x+1, used | (1<<j));
        }
        assign[x] = -1;
    }
}

int main() {
    fast();
    cin >> N;

    for (int i = 0; i < 30; ++i) assign[i] = -1;

    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        len[i] = s.length();

        for (int j = 0; j < len[i]; ++j) {
            if (!m1.count(s[j])) {
                m1[s[j]] = id++;
            }
            arr[i][j] = m1[s[j]];
        }
    }

    dfs(1, 0);

    cout << ans << endl;

    return 0;
}
