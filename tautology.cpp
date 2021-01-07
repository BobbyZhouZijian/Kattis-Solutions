#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void solve(string s) {
    int mask = 0;
    reverse(s.begin(), s.end());
    for (mask = 0; mask < (1 << 5); ++mask) {
        stack<bool> st;
        for (char c: s) {
            if (c - 'p' < 5 && c - 'p' >= 0) {
                bool b = (mask & (1 << (c - 'p'))) > 0;
                st.push(b);
            } else if (c == 'N') {
                bool t = st.top();
                st.pop();
                st. push(!t);
            } else {
                bool t1 = st.top(); st.pop();
                bool t2 = st.top(); st.pop();
                if (c == 'K') {
                    st.push(t1 && t2);
                } else if (c == 'A') {
                    st.push(t1 || t2);
                } else if (c == 'C') {
                    st.push(!t1 || t2);
                } else if (c == 'E') {
                    st.push(t1 == t2);
                }
            }
        }
        if (!st.top()) {
            cout << "not" << endl;
            return;
        }
    }
    cout << "tautology" << endl;
}

int main (){
    ios_base::sync_with_stdio(0);
    string s;
    while (cin >> s) {
        if (s == "0") {
            break;
        }
        solve(s);
    }
}