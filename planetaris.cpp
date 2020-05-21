#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a;
vector<int> c;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    cin >> n >> a;

    int cur;
    for(int i = 0; i < n; ++i) {
        cin >> cur;
        c.push_back(++cur);
    }

    sort(c.begin(), c.end());
    int ans = 0, i = 0;

    while(a > 0 && i < n) {
        a -= c[i++];
        if(a >= 0) ans++;
    }

    cout << ans;
}