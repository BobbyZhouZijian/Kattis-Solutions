#include <bits/stdc++.h>
using namespace std;

vector<string> w;

void solve(bool blank) {
    sort(w.begin(), w.end(), [](string s1, string s2) {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        return s1 < s2;
    });
    int len = 0;
    for (string &s : w) len = max(len, (int)s.length());

    for (string s : w) {
        for (int i = 0; i < len - s.length(); ++i) {
            cout << " ";
        }
        cout << s << endl;
    }
    if (blank) cout << endl;
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s.length() == 0) {
            solve(1);
            w.clear();
            continue;
        }
        w.push_back(s);
    }
    solve(0);
}