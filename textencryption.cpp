#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

ull solve(vector<pair<ull, ull>>& v,ull load) {
    int size = v.size();
    ull cost = v[size - 1].first * 2;
    for(int i = size - 1; i >= 0; --i) {
        ull cur_load = v[i].second;
        if(cur_load >= load) {
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
    ull n, load;

    vector<pair<ull, ull>> neg;
    vector<pair<ull, ull>> pos;

    while(n--) {
        ull p, l;
        cin >> p >> l;
        if(p < 0) neg.push_back({p, l});
        else pos.push_back({p, l});
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());

    ull cost = 0ull;
    while(neg.size()) cost += solve(neg, load);
    while(pos.size()) cost += solve(pos, load);

    cout << cost;
    
    return 0;
}