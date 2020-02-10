#include <iostream>
#include <cmath>
#include <iomanip>
#define N 1000
using namespace std;

double s[N], d[N], t;
int n;


void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

template<typename T>
void DEBUG(T x) { cout << x << " DEBUG" << endl; }

double sum(double c) {
    double ans = 0.0;
    for(int i = 0; i < n; ++i) {
        ans += d[i] / (s[i] + c);
    }

    return ans - t;
}


double minc = -10000.0, maxc = 1001000.0;

int main() {
    fast();
    cin >> n >> t;

    for(int i = 0; i < n; ++i) {
        double curd, curs;
        cin >> curd >> curs;
        d[i] = curd;
        minc = max(minc, -curs);
        s[i] = curs;
    }

    while(maxc - minc > 1e-8) {
        double mid = (maxc + minc) / 2.0;
        if(sum(mid) > 0.0) {
            minc = mid;
        }

        else if (sum(mid) < 0.0) {
            maxc = mid;
        }
        else break;
    }


    cout << fixed << setprecision(6) << (minc + maxc) / 2.0;
    return 0;
}
