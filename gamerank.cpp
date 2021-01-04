#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int rank = 25;
    int star =0;
    int consec = 0;
    map<int ,int > m;
    for (int i = 1; i <= 10; ++i) m[i] = 5;
    for (int i = 11; i <= 15; ++i) m[i] = 4;
    for (int i = 16; i <= 20; ++i) m[i] = 3;
    for (int i = 21; i <= 25; ++i) m[i] = 2;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'W') {
            consec++;
            star++;
            if (consec >= 3 && rank >= 6) {
                star++;
            }
            int need = m[rank];
            if (star > need) {
                rank--;
                star -= need;
            }
        } else {
            consec =0;
            if (rank == 20 && star == 0) continue;
            else if (rank <= 20) {
                if (star > 0) star--;
                else {
                    rank++;
                    star = m[rank] - 1;
                }
            }
        }

        if (rank == 0) break;
    }
    if (rank == 0) cout << "Legend" << endl;
    else cout << rank << endl;
}