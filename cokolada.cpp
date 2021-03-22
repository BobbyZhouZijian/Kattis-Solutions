#include <bits/stdc++.h>
using namespace std;

int pows[30];

int main() {
    pows[0] = 1;
    for (int i = 1; i < 30; ++i) {
        pows[i] = pows[i-1] << 1;
    }
    int n;
    cin >>n ;
    int p1 = log2(n);
    if (pows[p1] != n) p1++;
    else {
        cout << n << ' ' << 0 << '\n';
        return 0;
    }
    int size = pows[p1];
    int cnt = 0;
    while (n) {
        cnt++;
        p1--;
        if (pows[p1] <= n) {
            n -= pows[p1]; 
        }
    }
    cout << size << ' ' << cnt << '\n';
}

