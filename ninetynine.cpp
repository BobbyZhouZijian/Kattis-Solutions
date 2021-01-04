#include <iostream>
using namespace std;

int main() {
    int num = 2;
    int in;
    while (1) {
        cout << num << endl;
        if (num == 99) break;
        cin >> in;
        if (in == 99) break;
        if (in % 3 == 1) {
            num = in + 2;
        } else {
            num = in + 1;
        }
    }
}