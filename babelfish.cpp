#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, string> m;
    string s1, s2;
    while (!cin.eof()) {
        cin >> s1;
        if (cin.peek() == ' ') {
            cin >> s2;
            m[s2] = s1;
        } else if (!cin.eof()) {
            if (m.find(s1) == m.end()) {
                cout << "eh" << endl;
            } else {
                cout << m[s1] << endl;
            }
        }
    }
}