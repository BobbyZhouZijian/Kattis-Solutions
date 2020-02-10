#include <iostream>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

template<typename T>
void DEBUG(T x) { cout << x << " DEBUG" << endl; }

int main() {
    fast();

    int n, p, t = 0;
    cin >> n >> p;

    for(int i = 0; i < n; ++i) {
        int cur; cin >> cur;
        t += cur;
    }

    if (t >= n * p) {
        cout << 0;
    }
    else if (p == 100) {
        cout << "impossible";
    }

    else {
        int minm = (n * p - t) / (100 - p), maxm = n * p;
        while(minm < maxm) {
            int mid = (minm + maxm) / 2;
            if((t + 100 * mid) / (n + mid) < p) {
                minm = mid + 1;
            }
            else maxm = mid;
        }

        cout << minm;
    }
    return 0;
}