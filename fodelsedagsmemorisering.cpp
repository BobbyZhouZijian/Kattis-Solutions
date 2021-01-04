#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, pair<string, int>> m;
    string s, date;
    int like;
    for (int i = 0; i < n; ++i) {
        cin >> s >> like >> date;
        if (!m.count(date)) {
            m[date] = {s, like};
        } else {
            if (like > m[date].second) {
                m[date] = {s, like};
            }
        }
    }
    cout << m.size() << endl;
    vector<string> out;
    for (auto &it : m) {
        out.push_back(it.second.first);
    }
    sort(out.begin(), out.end());
    for (string o : out) cout << o << endl;
}