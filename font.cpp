#include <bits/stdc++.h>
using namespace std;

const int all = (1 << 26) - 1;
int n;

int words[30];

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    cin >> n;
    for (int i = 0 ; i < n; ++i) {
        string s;
        cin >> s;
        int cur = 0;
        for (char c : s) {
            cur |= (1 << (int)(c-'a'));
        }
        words[i] = cur;
    }

    int cnt = 0;

    for (int mask = 1; mask < (1 << n); ++mask) {
        int word = 0;
        int cur = mask;
        while (cur) {
            int least = cur & (-cur);
            cur -= least;
            int j = __builtin_ctz(least);
            word |= words[j];
            if (word == all) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}
