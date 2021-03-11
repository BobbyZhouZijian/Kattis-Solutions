#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int TC, n;

void solve() {
    cin >> n; 
    vector<ll> l,r;
    ll carry = 0;
    ll mult = 1;
    while (n) {
        int cur = n % 3 + carry;
        carry = 0;
        n /= 3;
        if (cur == 3) {
            carry = 1;
            cur = 0;
        }
        if (cur == 1) {
            r.push_back(mult);
        }
        if (cur == 2) {
            carry = 1;
            l.push_back(mult);
        }

        mult *= 3;
    }

    if (carry == 1) {
        r.push_back(mult);
    }

    sort(l.rbegin(), l.rend());
    sort(r.rbegin(), r.rend());
    cout << "left pan: ";
    for (ll i : l) cout << i << ' ';
    cout << '\n';
    cout << "right pan: ";
    for (ll i : r) cout << i << ' ';
    cout << "\n\n";
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    cin >> TC;
    while (TC--)
        solve();
}
