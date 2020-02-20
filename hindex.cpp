#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main() {

    fast();
    
    int n, cur;
    cin >> n;
    vector<long> hs;

    for(int i = 0; i < n; ++i) {
        cin >> cur;
        hs.push_back(cur);
    }

    sort(hs.begin(), hs.end(), greater<long>());

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(hs[i] > i) ans = i + 1;
    }

    cout << ans;
}