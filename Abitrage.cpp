#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main() {
    int n;

    while (cin >> n) {

        map<string, int> m;

        if (!n)
            break;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            m[s] = i;
        }
        
        int q;
        cin >> q;

        vector< vector<double> > v(n, vector<double>(n, 0));

        for (int i = 0; i < q; i++) {

            char s[4], t[4];
			double a, b;
			scanf("%s %s %lf:%lf", s, t, &a, &b);
			int x = m[s];
			int y = m[t];
			v[x][y] = max(v[x][y], b / a);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    v[i][j] = max(v[i][j], v[i][k] * v[k][j]);
                }
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (v[i][i] > 1.000001) {
                ok = false;
                break;
            }
        }

        if (ok)
            cout << "Ok" << endl;
        else
            cout << "Arbitrage" << endl;
    }
}