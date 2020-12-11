#include <bits/stdc++.h>
using namespace std;

int calc_seq(int num, int den) {
    if (num > den) {
        return calc_seq(num - den, den) * 2 + 1; 
    } else if (num < den) {
        return calc_seq(num, den - num) * 2;
    } else {
        return 1;
    }
}

int main() {
    int n;
    cin >> n;
    int c;
    int num, den;
    char j;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        cin >> num >> j >> den;
        cout << c << " " << calc_seq(num, den) << endl;
    }
}