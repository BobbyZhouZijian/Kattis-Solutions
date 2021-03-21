#include <bits/stdc++.h>
using namespace std;

int p,t;

int main() {
    cin >> p >> t;

    string s;
    int cnt = 0;
    for (int i = 0; i < p; ++i) {
        bool work = 1;
        for (int j = 0; j < t; ++j) {
            cin >> s;
            for (int k = 1; k < s.length() && work; ++k) {
                if (s[k] >= 'A' && s[k] <= 'Z') work = 0;
            }
        }
        if (work)  cnt ++;
    }

    cout << cnt << '\n';
}