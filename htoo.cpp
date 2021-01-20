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

string s;
int N;
string out;
map<char, int> m1, m2;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    fast();
    cin >> s >> N >> out;

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        int j = i + 1;
        int cnt = 0;
        while (j<s.length() && is_digit(s[j])) {
            int d = s[j] - '0';
            cnt = cnt * 10 + d;
            j++;
        }
        if (cnt == 0) m1[c] += N;
        else m1[c] += cnt * N;
        i = j-1;
    }


    for (int i = 0; i < out.length(); ++i) {
        char c = out[i];
        int j = i + 1;
        int cnt = 0;
        while (j < out.length() && is_digit(out[j])) {
            int d = (int) (out[j] - '0');
            cnt = cnt * 10 + d;
            j++;
        }
        if (cnt==0) m2[c]+=1;
        else m2[c] += cnt;
        i = j-1;
    }

    int maxm = INT_MAX;

    for (auto p : m2) {
        if (p.second > m1[p.first]) {
            maxm = 0;
            break;
        }
        maxm = min(maxm, m1[p.first] / p.second); 
    }

    cout << maxm << endl;

    return 0;
}
