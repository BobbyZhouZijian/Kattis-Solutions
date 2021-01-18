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

int N, Q;

ll vals[6];

vector<ll> ft[6];

void update(int t, int x, ll val) {
    auto& f = ft[t];

    while (x <= N) {
        f[x] += val;
        x += (x & (-x));
    }
}

ll rsq(vector<ll>& f, int r) {
    ll ans = 0;
    while (r) {
        ans += f[r];
        r -= (r & (-r));
    }
    return ans;
}

ll sum(int t, int l, int r) {
    return rsq(ft[t], r) - rsq(ft[t], l-1);
}

int main() {
    fast();

    cin >> N >> Q;

    for (int i = 0; i < 6; ++i) {
        cin >> vals[i];
        ft[i].resize(N + 1, 0);
    }

    vector<int> types(N+1,0);

    for (int i = 1; i <= N; ++i) {
        char c;
        cin >> c;
        int type = c - '1';
        types[i] = type;
        update(type, i, 1);
    }

    for (int i = 0; i < Q; ++i) {
        int t; cin >> t;
        if (t == 1) {
            ll k, p;
            cin >> k >> p;
            p--;
            int old_type = types[k];
            types[k] = p;
            update(old_type, k, -1);
            update(p, k, 1);
        } else if (t == 2) {
            ll p, v;
            cin >> p >> v;
            vals[p-1] = v;
        } else {
            ll l, r;
            cin >> l >> r;
            ll ans = 0;
            for (int i = 0; i < 6; ++i) {
                ans += sum(i, l, r) * vals[i];
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
