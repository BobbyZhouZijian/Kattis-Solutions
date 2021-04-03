#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;

int a1[MAXN], a2[MAXN], b[MAXN];

string T, P;

void buildTable() {
    int i = 0, j = -1;
    b[0] = -1;

    while (i < P.size()) {
        while ((j >= 0) && P[i] != P[j]) j = b[j];
        ++i; ++j;
        b[i] = j;
    }
}

bool kmpSearch() {
    int i = 0, j = -1;
    while (i < T.size()) {
        while ((j >= 0) && T[i] != P[j]) j = b[j];
        ++i; ++j;
        if (j == P.size()) return 1;
    }
    return 0;
}


string getText(int* a) {
    string out;
    int prev = a[n-1];
    for (int i = 0; i < n; ++i) {
        int t = a[i] - prev;
        if (t > 0) {
            out += ",";
            out += to_string(t);
        } else {
            out += to_string(t+360000);
        }
        prev = a[i];
    }

    return out;
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a2[i];
    }

    sort(a1, a1+n);
    sort(a2, a2+n);

    T = getText(a1);
    P = getText(a2);
    
    T = T + "," + T;
    buildTable();

    if (kmpSearch()) {
        cout << "possible\n";
    } else {
        cout << "impossible\n";
    }
}
