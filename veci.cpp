#include <bits/stdc++.h>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

char arr[10];

int main() {
    cin >> arr;
    int len = strlen(arr);
    int a = stoi(arr);
    sort(arr, arr+len);

    int minm = INT_MAX;
    do {
        int cur = stoi(arr);
        if (cur > a)
            minm = min(minm, cur);
    } while (next_permutation(arr,arr+len));

    minm == INT_MAX ? (cout << 0 << '\n') : (cout << minm << '\n');

    return 0;
}
