#include <bits/stdc++.h>
using namespace std;

int n;

double D,d,s;

void solve() {
    cin >> D >> d >> s;

    double doub_hypo = (D - d);
    double doub_oppo = (d + s);
    double deg = asin(doub_oppo / doub_hypo);

    int num = floor(M_PI / deg);

    cout << num << '\n';
}

int main() {
    cin >> n;
    while (n--) solve();
}