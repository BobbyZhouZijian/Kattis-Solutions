#include <iostream>
#include <iomanip>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main() {
    int n; cin >> n;
    while(n--) {
        double b, p;
        cin >> b >> p;
        cout << fixed << setprecision(6) << 60.0 * (b - 1.0) / p << " "
         << 60.0 * b / p << " "
         << 60.0 * (b + 1.0) / p << endl;
    }
}