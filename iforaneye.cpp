#include <bits/stdc++.h>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int n;

unordered_map<char, vector<string>> m;
unordered_map<string, char> m2;


int main() {
    fast();

    cin >> n;

    m['@'] = {"at"};
    m['&'] = {"and"};
    m['1'] = {"one", "won"};
    m['2'] = {"to", "too", "two"};
    m['4'] = {"for", "four"};
    m['b'] = {"bea", "be", "bee"};
    m['c'] = {"sea", "see"};
    m['i'] = {"eye"};
    m['o'] = {"oh", "owe"};
    m['r'] = {"are"};
    m['u'] = {"you"};
    m['y'] = {"why"};

    for (auto p : m) {
        for (string s : p.second) {
            m2[s] = p.first;
        }
    }


    string s;
    cin.ignore();
    while(n--) {
        getline(cin, s);
        string out;
        for (int i = 0; i < s.length(); ++i) {
            if (i+3<s.length()) {
                string cur;
                cur += (char)tolower(s[i]);
                cur += (char)tolower(s[i+1]);
                cur += (char)tolower(s[i+2]);
                cur += (char)tolower(s[i+3]);
                if (m2.count(cur)) {
                    if (isupper(s[i])) {
                        out += toupper(m2[cur]);
                    } else {
                        out += m2[cur];
                    }
                    i += 3;
                    continue;
                }
            }
            if (i+2<s.length()) {
                string cur;
                cur += (char)tolower(s[i]);
                cur += (char)tolower(s[i+1]);
                cur += (char)tolower(s[i+2]);
                if (m2.count(cur)) {
                    if (isupper(s[i])) {
                        out += toupper(m2[cur]);
                    } else {
                        out += m2[cur];
                    }
                    i += 2;
                    continue;
                }
            }
            if (i+1<s.length()){
                string cur;
                cur += (char)tolower(s[i]);
                cur += (char)tolower(s[i+1]);
                if (m2.count(cur)){
                    if (isupper(s[i])) {
                        out += toupper(m2[cur]);
                    } else {
                        out += m2[cur];
                    }
                    i++;
                    continue;
                }
            }
            out += s[i];
        }
        cout << out << "\n";
    }

    return 0;
}
