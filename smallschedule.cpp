#include <iostream>
#define debug(a) cout << #a << ": " << a << endl
using namespace std;

int main() {

    int q, m, s, l;
    cin >> q >> m >> s >> l;

    int ceil = l / m + (l % m != 0);
    int left = s - (ceil * m - l) * q;
    if(left <= 0) {
        cout << ceil * q;
    } else {
        cout << ceil * q + left / m + (left % m != 0);
    }
}
