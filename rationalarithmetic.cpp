#include <iostream>
using namespace std;

typedef long long ll;
ll x1, y1, x2, y2;
char op;

ll gcd(ll x1, ll x2) {
    x1 = abs(x1);
    x2 = abs(x2);
    if (x1 < x2) {
        swap(x1, x2);
    }
    if (x2 != 0) {
        return gcd(x1 % x2, x2);
    }
    return x1;
}

void process() {
    if (op == '+') {
        ll num = x1 * y2 + x2 * y1;
        ll den = y1 * y2;
        if (num < 0 && den < 0) {
            num = -num;
            den = -den;
        } else if (!(num > 0 && den > 0)) {
            num = -abs(num);
            den = abs(den);
        }
        ll div = gcd(num, den);
        cout << num / div << " / " << den / div << endl;
    }

    if (op == '-') {
        ll num = x1 * y2 - x2 * y1;
        ll den = y1 * y2;
        ll div = gcd(num, den);
        if (num < 0 && den < 0) {
            num = -num;
            den = -den;
        } else if (!(num > 0 && den > 0)) {
            num = -abs(num);
            den = abs(den);
        }
        cout << num / div << " / " << den / div << endl; 
    }

    if (op == '*') {
        ll num = x1 * x2;
        ll den = y1 * y2;
        ll div = gcd(num, den);
        if (num < 0 && den < 0) {
            num = -num;
            den = -den;
        } else if (!(num > 0 && den > 0)) {
            num = -abs(num);
            den = abs(den);
        }
        cout << num / div << " / " << den / div << endl; 
    }

    if (op == '/') {
        ll num = x1 * y2;
        ll den = y1 * x2;
        ll div = gcd(num, den);
        if (num < 0 && den < 0) {
            num = -num;
            den = -den;
        } else if (!(num > 0 && den > 0)) {
            num = -abs(num);
            den = abs(den);
        }
        cout << num / div << " / " << den / div << endl; 
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x1 >> y1 >> op >> x2 >> y2;
        process();
    }
}