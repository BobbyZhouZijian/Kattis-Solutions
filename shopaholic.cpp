#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[200005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);

    ll ans = 0;
    for (int i = n-1; i >= 2; i -= 3) {
        ans += static_cast<ll>(arr[i-2]); 
    }

    printf("%lld\n", ans);
}
