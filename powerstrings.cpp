#include <iostream>
#include <iterator>

using namespace std;

bool check(string& s, int i) {
    int n = s.length();
    for (int j = i; j < n; ++j) {
        if (s[j] != s[j - i]) return false;
    }
    return true;
}

int main() {
    string s;

    while (cin >> s) {
        if (s == ".") break;

        int n = s.length();
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0 && check(s, i)) {
                cout << n / i << endl;
                break;
            }
        }
    }
}

