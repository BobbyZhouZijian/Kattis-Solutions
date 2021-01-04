#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        int sz = a.length();
        int to1 = 0, to0 = 0, onediff = 0, total = 0;
        int ans = 0;
        for (int j = 0; j < sz; ++j) {
            if (a[j] != b[j]) {
                total++;
            }
            if (a[j] == '?' && b[j] == '1') {
                onediff--;
            } else if (a[j] == '0' && b[j] == '1') {
                onediff--;
                to1++;
            } else if (a[j] == '1' && b[j] == '0') {
                onediff++;
                to0++;
            }
        }
        if (onediff > 0) {
            ans = -1;
        } else {
            ans = total - min(to1, to0);
        }
        cout << "Case " << i + 1 << ": " << ans << endl;
    }
}