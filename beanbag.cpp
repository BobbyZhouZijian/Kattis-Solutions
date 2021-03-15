#include <bits/stdc++.h>
using namespace std;

int b,t;
int vs[30];
vector<vector<int>> ms;


bool check(int mask) {
    for (int i = 0; i < t; ++i) {
        bool ok = 0;
        for (int j : ms[i]) {
            if (mask & (1 << j)) {
                ok = 1;
                break;
            }
        }
        if (!ok)
            return 0;
    }
    return 1;
}

int main() {
    cin >> b;
    int sum = 0;
    for (int i = 0; i < b; ++i) {
        cin >> vs[i]; 
        sum += vs[i];
    }
    cin >> t;
    ms.assign(t+1,{});
    int x;
    for (int i = 0; i < t; ++i) {
        cin >> x; 
        for (int j = 0; j < x; ++j) {
            int k;
            cin >> k;
            ms[i].push_back(k-1);
        }
    }

    int best = 0;
    for (int mask = 0; mask < (1 << b); ++mask) {
        if (!check(mask)) continue;
        int cur = mask;
        int need = sum;
        while (cur) {
            int least = cur & (-cur);
            cur -= least;
            int j = __builtin_ctz(least);
            need -= vs[j]; 
        }
        best = max(best, need); 
    }

    cout << best << '\n';
}
