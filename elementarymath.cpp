#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<pair<ll,ll>> Vleft;
unordered_map<ll, ll> match;
vector<bool> vis;

vector<ll> possibles(int x) {
    auto [a,b] = Vleft[x]; 
    vector<ll> res;
    res.push_back(a+b);
    res.push_back(a-b);
    res.push_back(a*b);
    return res;
}

int aug(int L) {
    if (vis[L]) return 0;
    vis[L] = 1;
    for (auto &R : possibles(L)) {
        if (!match.count(R) || aug(match[R])) {
            match[R] = L;
            return 1;
        }
    }
    return 0;
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    cin >> n;
    ll a,b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        Vleft.push_back({a,b});
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        vis.assign(n+1,false);
        res += aug(i); 
    }
    if (res < n) {
        cout << "impossible\n";
    } else {
        vector<tuple<ll,ll,ll>> out(n+1);
        for (auto p : match) {
            auto [a,b] = Vleft[p.second];
            ll ret = p.first;
            out[p.second] = {a,b,ret};
        }

        for (int i = 0; i < n; ++i) {
            auto [a,b,ret] = out[i];
            if (ret == a * b)
                cout << a << " * " << b << " = " << ret << '\n';
            else if (ret == a + b)
                cout << a << " + " << b << " = " << ret << '\n';
            else
                cout << a << " - " << b << " = " << ret << '\n';
        }
    }
}
