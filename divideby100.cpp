#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s1 >> s2;
    int sz1 = s1.length(), sz2 = s2.length() - 1;
    if (sz2 == 0) {
        cout << s1 << endl;
    } else if (sz1 > sz2) {
        string left = s1.substr(sz1 - sz2);
        int i = left.length() - 1;
        while (i >= 0) {
            if (left[i] != '0') break;
            --i;
        }
        ++i;
        cout << s1.substr(0, sz1-sz2);
        if (i > 0) {
            cout << "." << left.substr(0, i);
        }
        cout << endl;
    } else {
        int diff = sz2-sz1;
        cout << "0.";
        for (int i = 0; i < diff; ++i) {
            cout << "0";
        }
        int i = s1.length() - 1;
        while (i >= 0){
            if (s1[i]!='0') break;
            --i;
        } 
        ++i;
        cout << s1.substr(0, i) << endl;
    }
}