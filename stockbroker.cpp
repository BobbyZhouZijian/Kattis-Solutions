#include <iostream>
#define MAX 100000
#define min(a, b) a < b ? a : b
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long ll;

int p[370], n;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();

    cin >> n;
    int cur;
    for(int i = 0; i < n; ++i) {
        cin >> cur;
        p[i] = cur;
    }

    ll cash = 100ll;
    for(int j = 1; j < n; ++j) {
        if(p[j] > p[j - 1]) {
            // profit
            ll change = min(MAX, cash / p[j - 1]);
            cash += change * (p[j] - p[j - 1]);
        }
        //debug(share);
        //debug(cash);
    }
    cout << cash;
}