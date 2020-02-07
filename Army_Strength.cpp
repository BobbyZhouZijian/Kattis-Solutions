#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    

    while (n-- > 0) {
        ll ng, nm;
        cin >> ng >> nm;
        ll maxng = 0, maxnm = 0;

        if (ng == 0 && nm == 0) {
            cout << "uncertain" << endl;
            continue;
        }

        for (ll i = 0; i < ng; i++) {
            ll curr;
            cin >> curr;
            maxng = max(maxng, curr);
        }

        for (ll i = 0; i < nm; i++) {
            ll curr;
            cin >> curr;
            maxnm = max(maxnm, curr);
        }

        if (maxng >= maxnm) {
            cout << "Godzilla" << endl;
        }

        else if (maxng < maxnm) {
            cout << "MechaGodzilla" << endl;
        }

    }
}