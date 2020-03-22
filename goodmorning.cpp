#include <iostream>
#include <string>
using namespace std;

int xpos[10] = {1,0,1,2,0,1,2,0,1,2},
    ypos[10] = {3,0,0,0,1,1,1,2,2,2};

double doable[210];

void getDoables() {
    for (int i = 0; i <= 200; ++i) {
        string str= to_string(i);
        bool ok = true;
        for (int j = 0; j < str.length() - 1; ++j) {
            if (xpos[str[j]-'0'] > xpos[str[j+1]-'0'] 
            || ypos[str[j]-'0']>ypos[str[j+1]-'0']) {
                ok = false;
                break;
            }
        }
        doable[i] = ok;
    }
}

int main() {
    getDoables();
    int cases;
    cin >> cases;
    while (cases--) {
        string cur;
        cin >> cur;
        int cur_int = stoi(cur);
        if (doable[cur_int]) {
            cout << cur << endl;
        } else {
            int lower = cur_int , higher = cur_int;
            while (lower--) {
                if (doable[lower]) break;
            }
            while (higher++ <= 200) {
                if (doable[higher]) break;
            }
            if (cur_int - lower <= higher - cur_int) {
                cout << lower <<endl;
            } else {
                cout << higher << endl;
            }
        }
    }
}