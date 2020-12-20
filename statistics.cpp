#include <bits/stdc++.h>
using namespace std;

int main() {
    int c = 1;
    while (1) {
        int minm = 10000001, maxm = -10000001, range = 20000001;
        int n, k;
        cin >> n;
        if (n == EOF) return 0;
        while (n--) {
            cin >> k;
            minm = min(minm, k);
            maxm = max(maxm, k);
        }
        range = maxm - minm;
        cout << "Case " << c << ": ";
        cout << minm << " " << maxm << " " << range << endl;
        c++;
    }
}