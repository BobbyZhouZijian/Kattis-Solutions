#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin.ignore();
    string s;
    map<string, int> m;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        stringstream ss(s);
        string token;
        while (getline(ss, token, ' ')) {
            continue;
        }
        for (auto &c : token) {
            c = tolower(c);
        }
        m[token]++;
    }

    for (auto [s, cnt] : m) {
        cout << s << " | " << cnt << '\n';
    }
}

int main() {
    int cnt = 1;
    while (cin >> n) {
        if (n == 0) break;
        cout << "List " << cnt++ << ":\n";
        solve();
    }
}