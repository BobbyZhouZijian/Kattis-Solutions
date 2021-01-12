#include <bits/stdc++.h>
using namespace std;

int L, A;

void solve() {
    vector<int> l, r;
    vector<int> v;
    char d;
    int pos;
    int tor = 0;
    for (int i = 0; i < A; ++i) {
        cin >> pos >> d;
        if (d == 'R') {
            tor++;
            r.push_back(L - pos);
        } else {
            l.push_back(pos);
        }
        v.push_back(pos);
    }
    sort(r.begin(), r.end());
    sort(l.begin(), l.end());
    sort(v.begin(), v.end());
    if (l.size() > 0 && (r.size() == 0 || l.back() > r.back())) {
        cout << "The last ant will fall down in " << l.back() << " seconds - started at ";
        cout << v[A-tor-1] << "." << endl;
    } else if (r.size() > 0 && (l.size() == 0 || r.back() > l.back())) {
        cout << "The last ant will fall down in " << r.back() << " seconds - started at ";
        cout << v[A-tor] << "." << endl;
    } else {
        cout << "The last ant will fall down in " << r.back() << " seconds - started at ";
        int pos1 = v[A-tor], pos2 = v[A-tor-1];
        if (pos1 > pos2) swap(pos1, pos2);
        cout << pos1 << " and " << pos2 << "." << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    while (cin >> L >> A) {
        solve();
    }
}