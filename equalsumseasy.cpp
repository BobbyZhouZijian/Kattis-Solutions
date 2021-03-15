#include <bits/stdc++.h>
using namespace std;

int TC, n;
int arr[21];

void print(int mask) {
    while (mask) {
        int least = mask & (-mask);
        mask -= least;
        int j = __builtin_ctz(least);
        cout << arr[j] << ' ';
    }
    cout << '\n';
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; 
    }

    unordered_map<int,int> m;

    for (int mask = 0; mask < (1 << n); ++mask) {
        int cur = mask;
        int sum = 0;
        while (cur) {
            int least = cur & (-cur);
            cur -= least;
            int j = __builtin_ctz(least);
            sum += arr[j];
        }
        if (m.count(sum)) {
            print(m[sum]);
            print(mask);
            return;
        } else {
            m[sum] = mask; 
        }
    }
    cout << "Impossible\n";
}

int main() {
    cin >> TC;
    int _case = 1;
    while (_case <= TC) {
        cout << "Case #" << _case++ << ":\n";
        solve();
    }
}
