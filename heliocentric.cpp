#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;

int mod(int a, int m) {
    return ((a%m) + m) % m;
}

int extEuclid(int a, int b, int &x, int &y) {
    int xx = y = 0;
    int yy = x = 1;
    while (b) {
        int q = a / b;
        int t = b; b = a % b; a = t;
        t = xx; xx = x - q*xx; x = t;
        t = yy; yy = y - q*yy; y = t;
    }
    return a;
}

int modInverse(int b, int m) {
    int x, y;
    int d = extEuclid(b, m, x, y);
    if (d != 1) return -1;
    return mod(x, m);
}

int crt(int r1, int r2) {
    int mt = 365 * 687;
    int x = 0;
    int a1 = mod(r1 * modInverse(687, 365), 365);
    x = mod(x + (ll)a1 * (687), mt);
    int a2 = mod(r2 * modInverse(365, 687), 687);
    //cout << "debug: " << a1 << ' ' << a2 << endl;
    x = mod(x + (ll)a2 * 365, mt);
    return x;
}

int main() {
    int id = 1;
    while (cin >> n >> m) {
        cout << "Case " << id++ << ": " << crt(365 - n, 687 - m) << "\n";
    }
}