#include <bits/stdc++.h>
using namespace std;

int n;

int to_int(string a) {
    int x = 0;
    for (char c : a) {
        x <<= 1;
        x += c - '0';
    }
    return x;
}

set<string> pal;

bool is_pal(string s) {
    int l = s.length();
    if (l == 0) return true;
    for (int i = 0; i < l / 2; ++i) {
        if (s[i] != s[l - i - 1]) return false;
    }
    return true;
}

void construct() {
    vector<string> sto;
    while (pal.size() < 2 * n) {
        for (string s : pal) {
            if (is_pal(s + "0")) {
                sto.push_back(s + "0");
            }
            if (is_pal("0" + s)) {
                sto.push_back("0" + s);
            }
            if (is_pal(s + "1")) {
                sto.push_back(s + "1");
            }
            if (is_pal("1" + s)) {
                sto.push_back("1" + s);
            }
            sto.push_back("1" + s + "1");
            sto.push_back("0" + s + "0");
        }
        for (string s : sto) {
            pal.insert(s);
        }
        sto.clear();
    }
}

int main() {
    cin >>n;
    pal.insert("");
    construct();

    set<int> v;

    for (string s : pal) {
        if (s == "" || s[0] == '0') continue;
        v.insert(to_int(s));
    }

    for (int i : v) {
        n--;
        if (n == 0) {
            cout << i << endl;
            break;
        }
    }
}