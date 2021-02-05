#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
unordered_map<string, int> m1;
unordered_map<int, string> m2;
vector<pair<int,int>> v;
int maxm[MAXN], minm[MAXN];
int n;

int find_max(int i, int j) {
    if (i > j) return 0;
    int res = v[j].second;
    for (int k = i; k < j; ++k) {
        res += v[k].second * (v[k+1].first - v[k].first);
    }
    if (i == 0) res -= 100;
    return res;
}

int find_min(int i, int j) {
    if (i > j) return 0;
    int res = v[i].second;
    for (int k = i+1; k <= j; ++k) {
        res += v[k].second * (v[k].first - v[k-1].first);
    }
    return res;
}

int main() {
    cin >> n;
    int id = 0;
    v.push_back({-1,100});
    for (int i = 0; i < n; ++i) {
        string s, c;
        cin >> s >> c;
        m1[s] = id;
        m2[id++] = s;
        if (c != "?") {
            v.push_back({i, stoi(c)});
        }
    }
    v.push_back({n, 0});

    int k = 1;
    
    for (int i = 0; i < n; ++i) {
        if (i == v[k].first) {
            maxm[i] = v[k].second;
            minm[i] =v[k].second;
            k++;
            continue;
        }
        int cur_min = find_min(1, k-1) + find_min(k, v.size()-1) + v[k].second * (v[k].first-i-1);
        maxm[i] = min(v[k-1].second, (100-cur_min) / (i-v[k-1].first));

        int cur_max = find_max(0, k-1) + find_max(k, v.size()-1);
        // cout << "***: " << k << ' ' << cur_max << endl;
        minm[i] = max(v[k].second, (100-cur_max) / (v[k].first - v[k-1].first-1));
    }

    for (int i = 0; i < n; ++i) {
        cout << m2[i] << ' ' << minm[i] << ' ' << maxm[i] << '\n';
    }
}
