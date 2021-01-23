#include <bits/stdc++.h>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int A, B;

void next(string &s){
    int carry = 0;
    for (int i = 0; i < s.length(); ++i) {
        s[i] += carry;
        carry = 0;
        if (s[i] < 'y') {
            s[i]++;
            return;
        } else {
            s[i] = 'a';
            carry = 1;
        }
    }
    if (carry)
        s += 'a';
}

int main() {
    fast();
    cin >> A >> B;
    string s = "a";
    int i = 0;
    int need = max(A, (B+1)/2);
    for (; i<need; ++i) {
        cout << s << ' ';
        next(s);
    }

    cout << '\n';

    return 0;
}
