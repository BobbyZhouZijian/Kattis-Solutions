#include <bits/stdc++.h>
using namespace std;

string c, s;

int main() {
    cin >> c >> s; 
    
    string out;
    if (c == "E") {
        int i = 0;
        while (i < s.length()) {
            int j = i+1;
            while (j<s.length() && s[j] == s[j-1])++j;
            int cnt = j-i;
            out += s[i];
            out += to_string(cnt);
            i = j;
        }
    } else {
        for (int i = 0; i < s.length(); i += 2) {
            char c = s[i];
            int cnt = s[i+1] - '0';
            for (int j = 0 ; j < cnt; ++j) {
                out += s[i];
            }
        }
    }

    cout << out << '\n';
}