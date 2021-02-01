#include <bits/stdc++.h>
using namespace std;

int n;

vector<string> v;

void build(int n) {
    if (n == 1) {
        v = {"1"};
        return;
    }

    build(n-1);

    vector<string> res;
    for (int i = 0 ; i < v.size(); ++i) {
        string s = v[i];
        if (i % 2 == 0) {
            s += (char)(n + '0');
            res.push_back(s);
            for (int j = s.length() - 2; j >= 0; --j) {
                swap(s[j], s[j+1]);
                res.push_back(s);
            }
        } else {
            s = (char)(n + '0') + s;
            res.push_back(s);
            for (int j = 0; j < s.length() - 1; ++j) {
                swap(s[j], s[j+1]);
                res.push_back(s);
            }
        }
    }

    v = res;
}

int main() {
    cin >> n;
    build(n);

    for (string &s : v) {
        for (char c : s) {
            cout << c << ' ';
        }
        cout << '\n';
    }
}
