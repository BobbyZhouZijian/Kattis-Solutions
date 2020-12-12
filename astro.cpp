#include <bits/stdc++.h>
using namespace std;

int to_index(int h, int m) {
    return h * 60 + m;
}

string to_time(int index) {
    int min = index % 60;
    int hr = index / 60;
    string h, m;
    if (hr >= 10) h = to_string(hr);
    else h = '0' + to_string(hr);
    if (min >= 10) m = to_string(min);
    else m = '0' + to_string(min);
    return h + ':' + m;
}


int main() {
    string to_dow[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    int h1,m1,h2,m2,ih1,im1,ih2,im2;
    char junk;
    cin >> h1 >> junk >> m1 >> h2 >> junk >> m2 >> ih1 >> junk >> im1 >> ih2 >> junk >> im2;
    int d = 0;
    bool f[1440];
 
    int s1 = to_index(h1, m1), s2 = to_index(h2, m2);
    int idx1 = to_index(ih1, im1);
    int idx2 = to_index(ih2, im2);
    bool found = false;
    while (1) {
        // reset
        fill(f, f + 1440, false); 
        while (s1 < 1440) {
            f[s1] = true;
            s1 += idx1;
        }
        s1 %= 1440;
        while (s2 < 1440) {
            if (f[s2]) {
                found = true;
                break;
            }
            s2 += idx2;
        }
        if (found) break;
        if (d > 1440) break;
        s2 %= 1440;
        d++;
    }
    if (found) {
        cout << to_dow[d % 7] << endl;
        cout << to_time(s2);
    } else {
        cout << "Never";
    }
}