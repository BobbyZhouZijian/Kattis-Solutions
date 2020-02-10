#include <iostream>
using namespace std;
typedef unsigned long long ull;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main() {

    fast();

    ull n, m;
    cin >> n >> m;

    ull weight = 1ull, ans = 0ull;

    for(ull node = 2ull; node <= n; ++node) {
        ans += weight;
        weight++; m--;
        ull wasted_edge = min(node - 2ull, m - (n - node));
        m -= wasted_edge;
        weight += wasted_edge;
    }

    cout << ans;
}