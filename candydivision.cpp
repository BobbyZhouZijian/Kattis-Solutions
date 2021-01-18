#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

ll N;

void solve() {
    queue<ll> q1;
    stack<ll> s1;
    for (ll i = 1; i < sqrt(N) + 1e-9; ++i) {
        if (N % i == 0) {
            q1.push(i-1);
            if (i!=N/i)
                s1.push(N/i-1);
        }
    }
    while (!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
}

int main() {
    fast();

    cin >> N;
    solve();

    return 0;
}
