#include <bits/stdc++.h>
using namespace std;

int n,m,d;

int main() {
    cin >> n >> m >> d;

    unordered_map<string, int> in;
    unordered_map<string, unordered_set<string>> wins;

    for (int i = 0; i < m; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        if(!in.count(s1)) in[s1] = 0;
        if (!in.count(s2)) in[s2] = 0;
        if (wins[s1].find(s2) == wins[s1].end()) {
            wins[s1].insert(s2);
            in[s2]++;
        }
    }

    vector<string> ranks;
    queue<string> q;
    for (auto p : in) {
        if (p.second == 0) {
            q.push(p.first); 
        }
    }

    while (!q.empty()) {
        string s = q.front(); q.pop();
        ranks.push_back(s);
        for (string s1 : wins[s]) {
            in[s1]--;
            if (in[s1] == 0)
                q.push(s1);
        }
    }

    unordered_map<string, int> ids;
    int id = 0;
    vector<int> v1,v2;
    for (string s : ranks) {
        v1.push_back(id);
        ids[s] = id++;
    }

    int edit = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        if (ids.count(s))
            v2.push_back(ids[s]);
        else
            edit++;
    }

    // LIS on v2
    int len = v2.size();
    int k = 0;
    vector<int> L(len+1, 0);

    for (int i = 0; i < len; ++i) {
        int pos = lower_bound(L.begin(), L.begin()+k, v2[i]) - L.begin();
        L[pos] = v2[i];
        if (pos == k) {
            k = pos + 1;
        }
    }

    cout << 2 * (len - k + edit) << endl;
}
