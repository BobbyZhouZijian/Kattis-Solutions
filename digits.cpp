#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (1) {
        cin >> s;
        if (s == "END") break;
        int len = s.size();
        int past = -1;
        if (len < 5) {
            past = stoi(s);
        }
        int cur = len;
        int cnt = 1;
        while (1) {
            if (cur == past) {
                cout << cnt << endl;
                break;
            }
            cnt++;
            int tmp = 0, cur2 = cur;
            while (cur2 > 0) {
                tmp++;
                cur2 /= 10;
            }
            past = cur;
            cur = tmp;
        }
    }
}