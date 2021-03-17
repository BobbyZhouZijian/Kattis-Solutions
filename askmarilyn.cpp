#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt = 1000;
    while (cnt--) {
        char out = 'A' + (rand() % 3);
        cout << out << endl;
        char a, b;
        cin >> a >> b;
        if (b == '1') {
            cout << a << endl;
        } else if (a == 'A') {
            if (out == 'B')
                cout << 'C' << endl; 
            else
                cout << 'B' << endl;
        } else if (a == 'B') {
            if (out == 'A')
                cout << 'C' << endl;
            else
                cout << 'A' << endl;
        } else {
            if (out == 'A')
                cout << 'B' << endl;
            else
                cout << 'A' << endl;
        }
        cin >> a >> b;
    }    
}
