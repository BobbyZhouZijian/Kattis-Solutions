#include <iostream>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();

    int n, a, b;
    cin >> n >> a >> b;

    a = max(a, n - a);
    b = max(b, n - b);

    cout << 4 * a * b;
}