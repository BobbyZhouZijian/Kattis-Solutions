#include <bits/stdc++.h>
using namespace std;

void solve(string s) {
    deque<string> dq;
    dq.push_back("");
    int pos = 0;
    for (char c : s) {
        if (c == '[') {
            dq.push_front("");
            pos = 0;
        } else if (c == ']') {
            pos = dq.size() - 1;
        } else if (c == '<') {
            if (dq[pos].size()) {
                dq[pos].pop_back();
            }
        } else {
            dq[pos].push_back(c);
        }
    }

    string res;
    for (string s : dq) {
        res += s;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        solve(s);
    }
}