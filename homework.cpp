#include <bits/stdc++.h>
using namespace std;

string s,s1,s2;

int memo[5005][5005];

bool match(int p1, int p2) {
    int p0 = p1+p2;
    if (p0 == s.length()) return 1;
    int &res = memo[p1][p2];
    if (res != -1) return res;

    res = 0;
    if (p2 < s2.length() && s[p0] == s2[p2])
        res |= match(p1,p2+1);
    if (p1 < s1.length() && s[p0] == s1[p1])
        res |= match(p1+1,p2);
    return res;    
}

int main() {
    memset(memo, -1, sizeof memo);
    cin >> s >> s1 >> s2;
    if (match(0,0))
        cout << "yes\n";
    else
        cout << "no\n";
}
