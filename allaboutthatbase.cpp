#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char, int> base;
map<int, char> back;

void initialize() {
    for (int i = 0; i < 9; ++i) {
        base['1' + i] = i + 1;
        back[i + 1] = '1' + i;
    }
    for (int i = 0; i < 26; ++i) {
        base['a' + i] = i + 10;
        back[i + 10] = 'a' + i;
    }
    base['0'] = 0;
    back[36] = '0';
}


bool is_valid(char op, int b, string x, string y, string z) {

    ll dx = 0, dy = 0, dz = 0;

    // edge case
    if (b == 1) {
        for (char i : (x + y + z)) {
            if (i != '1') return false;
        }
        dx = x.length();
        dy = y.length();
        dz = z.length();
    }
    else {
        for (char i : x) {
            dx *= b;
            int cur_b = base[i];
            if (cur_b >= b) return false;
            dx += cur_b;
            if (dx >= 4294967296LL) return false;
        }
        for (char i : y) {
            dy *= b;
            int cur_b = base[i];
            if (cur_b >= b) return false;
            dy += cur_b;
            if (dy >= 4294967296LL) return false;
        }
        for (char i : z) {
            dz *= b;
            int cur_b = base[i];
            if (cur_b >= b) return false;
            dz += cur_b;
            if (dz >= 4294967296LL) return false;
        }
    }

    // cout << "debug: " << dx << " " << dy << " " << dz << endl; // debug
    if (op == '+') return dx + dy == dz;
    if (op == '-') return dx - dy == dz;
    if (op == '*') return dx * dy == dz;
    else return dy != 0 && dx % dy == 0 && dx / dy == dz;
}

int main() {
    initialize();
    int n;
    cin >> n;
    string x, y, z;
    char op, junk;
    for (int i = 0; i < n; ++i) {
        cin >> x >> op >> y >> junk >> z;
        bool valid = false;
        for (int b = 1; b <= 36; ++b) {
            if (is_valid(op,b,x,y,z)) {
                valid = true;
                cout << back[b];
            }
        }
        if (!valid) cout << "invalid";
        cout << endl;
    }
}