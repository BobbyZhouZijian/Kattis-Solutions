#include<bits/stdc++.h>
using namespace std;

unordered_map<int, double> m;

int solve(int n) {
    double l = 0.0;
    for (int i = n; i >= 1; --i) {
        if (m[i] > 0) {
            l += m[i];
            break;
        }
        l += log10(i);
    }
    m[n] = l;
    return ((int) floor(m[n])) + 1;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == EOF) return 0;
        cout << solve(n) << endl;
    }
}