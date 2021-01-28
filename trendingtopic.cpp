#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> days;
map<int, vector<int>> q;
map<string, int> cnt;
int cur_day = 0;

void query(int j) {
    map<int, vector<string>> rev;
    for (auto p : cnt) {
        rev[p.second].push_back(p.first);
    }

    auto it = rev.rbegin();

    vector<pair<string, int>> res;
    while (res.size() < j && it != rev.rend()) {
        for (string p : it->second) {
            res.push_back({p, it->first});
        }
        it++;
    }

    auto cmp = [](pair<string, int> p1, pair<string, int> p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    };
    sort(res.begin(), res.end(), cmp);

    for (auto p : res) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

int main() {
    string s;
    days.push_back({});
    while (cin >> s) {
        if(s == "<text>") {
            days.push_back({});
            cur_day++;
            continue;
        } else if (s == "</text>") {
            continue;
        } else if (s == "<top") {
            int x;
            cin >> x;
            cin >> s;
            q[cur_day].push_back(x);    
        } else if (s.size() >= 4) {
            days[cur_day].push_back(s);
        }
    }

    days.emplace_back();
    cur_day++;


    for (int i = 0; i < cur_day; ++i) {
        for (string j : days[i]) {
            cnt[j]++;
        }
        if (i >= 7) {
            for (string j : days[i-7]) {
                cnt[j]--;
                if (cnt[j]==0) cnt.erase(j);
            }
        }
        for (int j : q[i]) {
            cout << "<top " << j << ">" << '\n';
            query(j);
            cout << "</top>\n";
        }
    }
}
