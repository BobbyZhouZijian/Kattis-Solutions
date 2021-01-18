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

int N;
int ans=0;

void solve() {
    stack<int> st;
    for (int i = 0; i < 2 * N; ++i) {
        int x; cin >> x;
        if (!st.empty() && st.top() == x) {
            ans++;
            st.pop();
        } else {
            ans++;
            st.push(x);
        }
    }
    if (st.empty())
        cout << ans << endl;
    else
        cout << "impossible" << endl;
}

int main() {
    fast();
    cin >> N;
    solve();

    return 0;
}
