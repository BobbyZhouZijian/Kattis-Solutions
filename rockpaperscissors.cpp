#include <bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(3) << fixed;
    int n, k;
    while (cin >> n) {
        if (n == 0) break;
        cin >> k;
        int games = k *(n - 1) * n / 2;
        vector<int> w(n, 0), l(n, 0);
        int a, b;
        string p1, m1;
        while (games--) {
            cin >> a >> p1 >> b >> m1;

            a--; b--;

            if (p1 == m1) continue;
            if (p1 == "rock" && m1 == "paper") {
                l[a]++; w[b]++;
            }
            if (m1 == "rock" && p1 == "paper") {
                w[a]++; l[b]++;
            }
            if (p1 == "rock" && m1 == "scissors") {
                w[a]++; l[b]++;
            }
            if (m1 == "rock" && p1 == "scissors") {
                w[b]++; l[a]++;
            }
            if (p1 == "paper" && m1 == "scissors") {
                l[a]++; w[b]++;
            }
            if (m1 == "paper" && p1 == "scissors") {
                l[b]++; w[a]++;
            }
        }

        for (int i = 0; i < n; ++i) {
            int x = w[i], y = l[i];
            if (x + y == 0) {
                cout << "-" << endl;
            } else {
                cout << (double) x / (x + y) << endl;
            }
        }
        cout << endl;
    }
}