#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    for (char c : s) {
        if (c == '<') {
            st.pop();
        } else {
            st.push(c);
        }
    }
    string out;
    while (!st.empty()) {
        out += st.top();
        st.pop();
    }

    reverse(out.begin(), out.end());
    cout << out;
}