#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int N;

int main() {
    fast();
    string s;
    getline(cin, s);
    cin >> N;
    cin.ignore();
    vector<string> original;
    vector<vector<string>> v(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, s);
        original.push_back(s);
        string cur;
        int len = s.length();
        for (int j = 0; j < len; ++j) {
            if (j+1 < len && s[j] == ',' && s[j+1] == ' ') {
                v[i].push_back(cur);
                cur.clear();
                ++j;
            } else {
                cur += s[j];
            }
        }
        if (cur.length() > 0)
            v[i].push_back(cur);
    }

    vector<int> maxm(N, 0);

    int minm = INT_MAX;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i==j) continue;
            int cnt = 0;
            for (int k = 0; k < v[i].size(); ++k) {
                if (v[i][k] != v[j][k]) cnt++;
            }
            maxm[i] = max(maxm[i], cnt);
        }

        minm = min(minm, maxm[i]);
    }

    for (int i = 0; i < N; ++i) {
        if (maxm[i] == minm) cout << original[i] << "\n";
    }

    return 0;
}
