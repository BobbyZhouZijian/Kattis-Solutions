#include <bits/stdc++.h>
using namespace std;

bool solve(int x, int y) {
    if (x < y) {
        swap(x, y);
    }
    if (y == 0) return false;
    if (x % y == 0) return true;

    bool ans = !solve(x%y, y);
    if (!ans && x/y > 1) {
        ans = !solve(y+x%y, y);
    }
    return ans;
}

int main() {
    int x, y;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) break;
        if (solve(x, y)) {
            cout << "Stan wins" << endl;
        } else {
            cout << "Ollie wins" << endl;
        }
    }
}