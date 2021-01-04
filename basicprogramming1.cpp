#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    vector<signed int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    if (t == 1) {
        cout << "7" << endl;
        return 0;
    } else if (t == 2) {
        if (A[0] > A[1]) {
            cout << "Bigger" << endl;
        } else if (A[0] == A[1]) {
            cout << "Equal" << endl;
        } else {
            cout << "Smaller" << endl;
        }
    } else if (t == 3) {
        sort(A.begin(), A.begin()+3);
        cout << A[1] << endl;
    } else if (t == 4) {
        ll sum = 0;
        for (auto i : A) sum += (ll)i;
        cout << sum << endl;
    } else if (t == 5) {
        ll sum = 0;
        for (auto i : A) if (i % 2 == 0) sum += (ll)i;
        cout << sum << endl;
    } else if (t == 6) {
        string res = "";
        for (auto i : A) res += (char)('a' + (i % 26));
        cout << res << endl;
    } else if (t == 7) {
        int i = 0;
        vector<bool> vis(n, false);
        while (1) {
            if (vis[i]) {
                cout << "Cyclic" << endl;
                return 0;
            }
            vis[i] = true;
            if (A[i] >= n || A[i] < 0) {
                cout << "Out" << endl;
                return 0;
            }
            i = A[i];
            if (i == n - 1) {
                cout << "Done" << endl;
                return 0;
            }
        }
    }
}