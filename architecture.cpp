#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int me = 0, mn = 0;
    int num;
    for (int i = 0; i < r; ++i) {
        cin >> num;
        me = max(me, num);
    }
    for (int i = 0; i < c; ++i) {
        cin >> num;
        mn = max(mn, num);
    }
    if (me == mn) cout << "possible";
    else cout << "impossible";
}