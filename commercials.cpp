#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,p;
    cin >> n>> p;
    vector<int> v;
    for (int i = 0;i < n; ++i) {
        int x; cin>>x;
        x-=p;
        v.push_back(x);
    }
    
    int sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }
    cout << ans << endl;
}
