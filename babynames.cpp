#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<string, null_type, less<string>, rb_tree_tag,
    tree_order_statistics_node_update> ost;

ost t1, t2;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    unordered_set<string> m(2e5*2);
    int t;
    while (cin >> t, t) {
        if (t == 1) {
            string s;
            cin >> s;
            int g; cin >> g;
            if (g == 1) {
                t1.insert(s);
                m.insert(s);
            } else {
                t2.insert(s);
            }
        } else if (t == 2) {
            string s; cin >> s;
            if (m.find(s) != m.end()) {
                t1.erase(t1.find(s));
                m.erase(s);
            } else {
                t2.erase(t2.find(s));
            }
        } else if (t == 3) {
            string s1, s2;
            int g;
            cin >> s1 >> s2 >> g;
            if (g == 0) {
                int n2 = t2.order_of_key(s2) - t2.order_of_key(s1);
                int n1 = t1.order_of_key(s2) - t1.order_of_key(s1);
                cout << n1 + n2 << "\n";
            } else if (g == 1) {
                int n1 = t1.order_of_key(s2) - t1.order_of_key(s1);
                cout << n1 << "\n";
            } else {
                int n2 = t2.order_of_key(s2) - t2.order_of_key(s1);
                cout << n2 << "\n";
            }
        }
    }
}

