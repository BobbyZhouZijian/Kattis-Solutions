#include <iostream>
#include <cmath>
#define PI 3.1415926535897932384626433832795
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

template<typename T>
void DEBUG(T x) { cout << x << " DEBUG" << endl; }

int main() {
    fast();

    int n; cin >> n;
    while(n--) {
        double v0, theta, x1, h1, h2;
        cin >> v0 >> theta >> x1 >> h1 >> h2;
        theta = theta * PI / 180.0;
        double t = x1 / (v0 * cos(theta)),
            y = x1 * tan(theta) - 0.5 * 9.81 * t * t;
        //DEBUG(y);
        if (y < h2 - 1.0 && y > h1 + 1.0) cout << "Safe" << endl;
        else cout << "Not Safe" << endl;
    }

    return 0;
}
