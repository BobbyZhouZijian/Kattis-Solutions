#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, r;
    cin >> n >> k >> r;
    vector<int> dna(n);
    vector<int> counts(k, 0);
    for (int i = 0; i < n; ++i) {
        cin >> dna[i];
        counts[dna[i]]++;
    }
    map<int, int> rep;
    int b, q;
    int num = 0;
    for (int i = 0; i < r; ++i) {
        cin >> b >> q;
        if (q > counts[b]) {
            cout << "impossible" << endl;
            return 0;
        }
        rep[b] = q;
        num++;
    }
    
    int minm = INT_MAX;

    map<int, int> cur;

    int i = 0, j = 0;
    while (1) {
        if (num > 0) {
            if (j == n) break;
            cur[dna[j]]++;
            if (cur[dna[j]] == rep[dna[j]]) num--;
            j++;
        } else {
            minm = min(minm, j - i);
            if (cur[dna[i]] == rep[dna[i]]) num++;
            cur[dna[i]]--;
            i++;
        }
    }
    cout << minm << endl;
}