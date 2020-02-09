#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

ll solve(vector<pair<ll, ll>>& v, ll load) {
    int size = v.size();
    ll cost = v[size - 1].first * 2;
    for(int i = size - 1; i >= 0; --i) {
        ll cur_load = v[i].second;
        if(cur_load > load) {
            v[i].second -= load;
            break;
        }
        else {
            load -= cur_load;
            v.pop_back();
        }
    }

    return cost;
}

int main() {

    fast();

    ll n, load;
    cin >> n >> load;

    vector<pair<ll, ll>> neg;
    vector<pair<ll, ll>> pos;

    while(n--) {
        ll p, l;
        cin >> p >> l;
        if(p < 0) neg.push_back({-p, l});
        else pos.push_back({p, l});
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    ll cost = 0ll;
    while(neg.size()) cost += solve(neg, load);
    while(pos.size()) cost += solve(pos, load);

    cout << cost;
    
    return 0;
}