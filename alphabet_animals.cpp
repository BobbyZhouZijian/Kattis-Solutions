#include <iostream>
#include <map>
#include <vector>
using namespace std;



int main() {
    map< char, vector<string> > m;
    string init;
    int n;
    cin >> init >> n;

    for (int i = 0; i < n; i++) {
        string curr;
        cin >> curr;
        char f = *curr.begin();
        m[f].push_back(curr);
    }

    string ans = "?";
    char last = *init.rbegin();

    if (m[last].size() == 0) {
        cout << ans;
        return 0;
    }

    for (auto nb : m[last]) {
        char l = *nb.rbegin();
        int cnt = 0;
        for (auto next : m[l]) {
            if (next == nb) continue;
            else {
                cnt++;
                break;
            }
        }

        if (!cnt) {
            ans = nb;
            break;
        }
    }

    if (ans == "?") {
        cout << *m[last].begin();
    }

    else cout << ans << "!";
}