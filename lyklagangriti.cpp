#include <iostream>
#include <deque>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    deque<char> left, right;
    for (char c : s) {
        if (c == 'R') {
            char top = right.front();
            right.pop_front();
            left.push_back(top);
        } else if (c == 'L') {
            char top = left.back();
            left.pop_back();
            right.push_front(top);
        } else if (c == 'B') {
            left.pop_back();
        } else {
            left.push_back(c);
        }
    }
    string res = "";
    for (char c : left )res += c;
    for (char c : right) res += c;
    cout << res << endl;
}