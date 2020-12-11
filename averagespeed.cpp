#include <bits/stdc++.h>
using namespace std;

double calc_elapse_time(int h1, int m1, int s1, int h2, int m2, int s2) {
    return (double)(h2 - h1) + (m2 - m1) / 60.0 + (s2 - s1) / 3600.0;
}

string format(int d) {
    if (d >= 10) return to_string(d);
    else {
        return '0' + to_string(d);
    }
}

int main() {
    cout << setprecision(2) << fixed;
    int speed = 0;
    double dist = 0.0;
    int lh = 0, lm = 0, ls = 0;
    int hour, min, sec;
    char col;
    while (cin >> hour >> col >> min >> col >> sec) {
        dist += speed * calc_elapse_time(lh, lm, ls, hour, min, sec);
        if (cin.peek() == ' ') {
            cin >> speed;
        } else {
            cout << format(hour) << ":" << format(min) << ":" << format(sec) << " " << dist << " km" << endl;
        }
        lh = hour; lm = min; ls = sec;
    }
}