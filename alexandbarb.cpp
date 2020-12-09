#include <bits/stdc++.h>
using namespace std;

int k, m, n;

bool solve() {
    return k % (m + n) >= m;
}

int main() {
    cin >> k >> m >> n;
    if (solve()) cout << "Alex" << endl;
    else cout << "Barb" << endl;
}