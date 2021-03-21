#include <bits/stdc++.h>
using namespace std;

char rotate(char c, int val) {
    val = val % 26;
    int shift = ((c-'A') + val) % 26;
    return 'A' + shift;
}

int main() {
    string s;
    cin >> s;
    int v1 = 0, v2 = 0, n = s.length();
    for (int i = 0; i < n/2; ++i) {
        v1 += s[i] - 'A';
        v2 += s[i+n/2] - 'A';
    }

    for (int i = 0; i < n/2; ++i) {
        s[i] = rotate(s[i], v1);
        s[i+n/2] = rotate(s[i+n/2], v2);
    }

    for (int i = 0; i < n/2; ++i) {
        cout << rotate(s[i], s[i+n/2]-'A');
    }
}