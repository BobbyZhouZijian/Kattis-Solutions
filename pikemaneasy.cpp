#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, t, a, b, c, t0;
    cin >> n >> t >> a >> b >> c >> t0;
    vector<ll> v = {t0};
    for (int i = 0; i < n - 1; ++i) {
        ll tmp = (a * t0 + b) % c + 1LL;
        v.push_back(tmp);
        t0 = tmp; 
    }
    sort(v.begin(), v.end());
    int num = 0;
    ll time = 0LL;
    ll accum = 0LL;
    for (int i = 0; i < v.size(); ++ i) {
        time += v[i];
        if (time <= t) {
            num += 1;
            accum = (accum + time) % 1000000007;
        } else {
            break;
        }
    }
    cout << num << " " << accum;
}