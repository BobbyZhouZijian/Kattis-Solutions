#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n, xh,yh,xw,yw, L[MAXN];
pair<int,int> arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> xh >> yh >> xw >> yw;
    if (xh > xw) {
        swap(xh, xw);
        swap(yh, yw);
    }

    bool reflect = false;
    if (yw < yh) {
        reflect = true;
        yw = -yw;
        yh = -yh;
    }

    arr[0] = {xh,yh};
    arr[1] = {xw,yw};
    int cnt = 2;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (reflect) y = -y;
        if (x < xh || x > xw || y < yh || y > yw) continue;
        arr[cnt++] = {x,y};
    }
    
    sort(arr, arr+cnt);

    int k = 0;
    for (int i = 0; i < cnt; ++i) {
        int pos = upper_bound(L, L+k, arr[i].second) - L;
        L[pos] = arr[i].second;
        if (pos == k) ++k;
    }

    cout << k - 2 << endl;
}
