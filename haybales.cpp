#include <bits/stdc++.h>
using namespace std;

string s;

bool check2() {
    for (int i = 0; i < s.length() - 2; ++i) {
        if (s[i]=='P' && s[i+2] =='C') {
            s[i] = 'C';
            s[i+2] = 'P';
            return true;
        }
    }
    return false;
}

bool check1() {
    for (int i = 0; i +1 < s.length(); ++i) {
        if (s[i] == 'P' && s[i+1] == 'C') {
            s[i] = 'C';
            s[i+1] = 'P';
            return true;
        }
    }
    return false;
}

int main() {
    cin >> s;
    int ans = 0;
    while (1) {
        while (check2()) {
            ans++;
        }
        if (check1()) {
            ans++;
        } else break;
    }
    cout << ans << '\n';
}
