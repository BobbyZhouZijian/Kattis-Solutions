#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        vector<int> ns, ms;
        int curn, curm;
        for(int i = 0; i < n; ++i) {
            cin >> curn;
            ns.push_back(curn);
        }
        for(int i = 0; i < m; ++i) {
            cin >> curm;
            ms.push_back(curm);
        }

        sort(ns.begin(), ns.end());
        sort(ms.begin(), ms.end());

        int i = 0, j = 0, c = 0;
        while(i < n && j < m) {
            if(ns[i] > ms[j]) j++;
            else {
                c += ms[j]; i++; j++;
            }
        }
        if(j == m && i < n) cout << "Loowater is doomed!";
        else cout << c;
        cout << "\n";
    }
}