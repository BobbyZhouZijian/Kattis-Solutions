#include <bits/stdc++.h>
using namespace std;

int TC; 

int b, k;

bitset<10000010> bs;
vector<int> p;

void solve() {
    cin >> b >> k;
    b--;
    
    int res = -1;
    for(int i=1; i<=sqrt(b); ++i) {
        if (b % i == 0) {
            if  (b/i > k && i <= k) {
                res = max(res, i); 
            } else if (b/i <= k) {
                res = max(res, b/i);
            }
        }
    }

    cout <<  res << '\n';
}

int main() {
    cin >> TC;
    while (TC--) solve();
}
