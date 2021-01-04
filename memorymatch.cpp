#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a, b, id = 0;
    string c1, c2;
    map<string , int> m;
    vector<int> cards(n, -1);
    for (int i = 0; i < k; ++i) {
        cin >> a >> b >> c1 >> c2;
        if (!m.count[c1]) m[c1] = id++;
        if (!m.count[c2]) m[c2] = id++;
        if (c1 == c2) {
            cards[a] = -1;
            cards[b] = -1;
        } else {
            cards[a] = m[c1];
            cards[b] = m[c2];
        }
    }
     
}