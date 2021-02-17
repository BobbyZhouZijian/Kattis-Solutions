#include <bits/stdc++.h>
using namespace std;

int n;

int arr[50005];

int main() {
    while (scanf("%d", &n)) {
        if (n == 0) break;
        for (int i = 0 ; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        sort(arr, arr+n);

        printf("%d-A ", arr[0]);
        int tmp = 1;
        for (int k = n-1; k>0; --k) {
            printf("%d-%c ", arr[k], 'A'+tmp);
            tmp = 1-tmp;
        }

        printf("\n");
    }
}
