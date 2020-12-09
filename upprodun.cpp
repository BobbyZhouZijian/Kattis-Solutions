#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int r = m % n;
    int d = m / n;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < d + 1; ++j)
            cout << '*';
        cout << endl;
    }
    for (int i = r; i < n; ++i) {
        for (int j = 0; j < d; ++j)
            cout << '*';
        cout << endl;
    }
}