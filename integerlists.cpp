#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases;
    string in;
    getline(cin, in);
    cases = stoi(in);

    while (cases--) {
        string program;
        getline(cin, program);
        getline(cin, in);
        int l = stoi(in);

        getline(cin, in);
        deque<int> v;
        string trimmed;
        
        if (l > 0) {
            trimmed = in.substr(1, in.length() - 1);
        } else {
            trimmed = "";
        }
        string s = "";
        for (char c : trimmed) {
            if (c == ',') {
                v.push_back(stoi(s));
                s = "";
            } else {
                s += c;
            }
        }
        if (s != "") v.push_back(stoi(s));

        bool rev = false, err = false;

        for (char c : program) {
            if (c == 'R') rev = !rev;
            if (c == 'D') {
                if (v.size() == 0) {
                    err = true;
                    break;
                }
                if (rev) {
                    v.pop_back();
                } else {
                    v.pop_front();
                }
            }
        }
        if (err) {
            cout << "error" << endl;
        } else {
            cout << "[";
            int n = v.size();
            if (rev) {
                for (int i = 0; i < n; ++i) {
                    int k = v.back(); v.pop_back();
                    cout << k;
                    if (i < n - 1) cout << ",";
                }
            } else {
                for (int i = 0; i < n; ++i) {
                    int k = v.front(); v.pop_front();
                    cout << k;
                    if (i < n - 1) cout << ",";
                }
            }
            cout << "]" << endl;
        }
    }
}