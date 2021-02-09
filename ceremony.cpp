#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr.rbegin(), arr.rend());
    int pos = 0;
    int last = n-1;
    int cnt = 0;
    int offset=0;
    while (pos <= last) {
        cnt++;
        if (arr[pos]-offset > last-pos+1) {
            pos++;
        } else {
            offset++;
            while (last >= pos && offset == arr[last]) last--;
        }
    }
    printf("%d\n", cnt);
}
