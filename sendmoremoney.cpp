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

int chars[26] = {0};
int assign[105];
int id = 1;
int a1[100], a2[100], a3[100];
int l1, l2, l3;
int all = (1 << 10) - 1;

bool check() {
    if (assign[a1[0]] == 0 || assign[a2[0]] == 0 || assign[a3[0]] == 0) return false;
    int carry = 0;
    for (int j = 0; j < l3; ++j) {
        int sum = carry;
        int v1 = l1-j-1 < 0 ? 0 : assign[a1[l1-j-1]]; 
        int v2 = l2-j-1 < 0 ? 0 : assign[a2[l2-j-1]];
        int v3 = assign[a3[l3-j-1]];
        if (v1==-1 || v2==-1 || v3==-1) return true;
        sum += v1 + v2;
        if (sum % 10 != v3) return false;
        carry = sum / 10;
    }
    return carry == 0;
}

bool dfs(int x, int used) {
    if (x == id) {
        return true;     
    }
    int can = all ^ used;
    while (can) {
        int pos = (can & (-can));
        can -= pos;
        int j = __builtin_ctz(pos);
        assign[x] = j;
        if (check())
            if (dfs(x+1, used | (1<<j))) return true;
        assign[x]=-1;
    }
    return false;
}

int main() {
    fast();
    string s;
    cin >> s;

    for (int i = 0; i < 105; ++i) assign[i] = -1;

    int state = 0;
    int i = 0;
    for (char c : s) {
        if (c=='=' || c=='+') continue;
        if (chars[c-'A']==0) {
            chars[c-'A']=1;
        }
    }
    for (int k = 0; k < 26; ++k) {
        if (chars[k]) {
            chars[k] = id++;
        }
    }

    for (char c : s) {
        if (c == '+' || c == '=') {
            if(state==0) l1=i;
            else if (state==1) l2=i;
            state++;
            i = 0;
            continue;
        }
        int val = chars[c-'A'];
        if (state==0) {
            a1[i++] = val;
        } else if (state==1) {
            a2[i++] = val; 
        } else {
            a3[i++] = val;
        }
    }
    l3 = i;

    if (l3 >= max(l1,l2) && dfs(1, 0)) {
        for (int i=0; i < l1; ++i) {
            cout << assign[a1[i]];
        }
        cout << "+";
        for (int i = 0; i < l2; ++i) {
            cout << assign[a2[i]];
        }
        cout << "=";
        for (int i = 0; i < l3; ++i) {
            cout << assign[a3[i]];
        }
        cout << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}
