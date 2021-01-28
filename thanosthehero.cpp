#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main() {
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] < i) {
            printf("1\n");
            return 0;
        }
    }

    ll cnt = 0;
    for (int i = n-1; i>=0; --i) {
        if (i<n-1 && arr[i]>= arr[i+1]) {
            cnt += static_cast<ll>(arr[i]-arr[i+1]+1);
            arr[i] = arr[i+1]-1;
        }
        if (arr[i] < i) {
            cnt = 1;
            break;
        }
    }
    printf("%lld\n", cnt);

    return 0;
}
