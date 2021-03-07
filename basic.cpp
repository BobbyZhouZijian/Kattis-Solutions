#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int TC;
string s;
map<char, int> m;

void solve() {
    cin >> s;
    bool wrong = false;
    ll base = 10, num = 0;
    bool isEmpty = true;
    bool greater16 = false;
    bool openBracket = false;
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == '#') {
            if (openBracket) {
                if (isEmpty) {
                    wrong = true;
                    break;
                }
                openBracket = false;
            }else {
                openBracket = true;
                if (greater16 || base < 2) {
                    wrong = true;
                    break;
                } else {
                    base = num;
                    num = 0;
                }
                isEmpty = true;
            }

            continue;
        }
        isEmpty = false;
        if (m.count(c) ==0 ) {
            wrong = true;
            break;
        }
        int v = m[c];
        if (v >= base) {
            wrong = true;
            break;
        }
        num*=base;
        num+=v;
        if (num > 16) {
            greater16 = true;
        }
    }
    if (openBracket||wrong) {
        cout<<"no\n";
    } else {
        cout<<"yes\n";
    }


}

void initialize() {
    m['0'] = 0;
    m['1'] = 1;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
    m['a'] = 10;
    m['b'] = 11;
    m['c'] = 12;
    m['d'] = 13;
    m['e'] = 14;
    m['f'] = 15;
}

int main() {
    initialize();
    cin >> TC;
    while (TC--)
        solve();
    return 0;
}

