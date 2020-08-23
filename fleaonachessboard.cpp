#include <iostream>
using namespace std;

bool is_on_white(int x, int y, int S) {
    if (x % S == 0 || y % S == 0) return false; // boundary does not count
    return ((x / S) + (y / S)) % 2;
}

int main() {
    int S, x, y, dx, dy;
    while (1) {
       cin >> S >> x >> y >> dx >> dy;
       if (!S) break;
        
       int count = 0;
       for (count = 0; count < 2 * S; count++) {
            if (is_on_white(x, y, S)) {
                cout << "After " << count << " jumps the flea lands at (" << x << ", " << y << ")." << endl;
                break;
            }
            x += dx;
            y += dy;
       }
       
       if (count >= 2 * S) {
            cout << "The flea cannot escape from black squares." << endl;
       }
    }
}