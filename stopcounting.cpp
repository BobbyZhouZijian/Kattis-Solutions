#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int n;
ll *arr;

int main() {
    scanf("%d",&n);
    arr = (ll*) malloc(sizeof(ll) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&arr[i]); 
    }

    ld res = 0.0;
    ll a1 = 0, a2 = 0;
    for (int i = 0; i < n; ++i) {
        a1 += arr[i];
        res = max(res, a1 / (ld)(i+1));
    }
    for (int i = n-1; i >= 0; --i) {
        a2 += arr[i];
        res = max(res, a2 / (ld)(n-i));
    }
    
    printf("%llf\n", res);
}
