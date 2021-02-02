#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int TC, n;
pair<int, int> arr[MAXN];
int L[MAXN], k;

void LIS(int x) {
    int pos = upper_bound(L, L+k, x) - L;
    L[pos] = x;
    if (pos == k) {
        ++k; 
    }
}

void solve() {
    scanf("%d", &n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        arr[i] = {x,-y};
    }
     
    k = 0;
    sort(arr, arr+n);
    for (int i = 0; i < n; ++i) {
        LIS(arr[i].second);
    }

    printf("%d\n", k);
}

int main() {
    scanf("%d", &TC);
    while (TC--)
        solve();
}
