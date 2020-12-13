#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> w;

int find(int i) {
    if (v[i] == -1) {
        return i;
    } else {
        v[i] = find(v[i]);
        return v[i];
    }
}

void join(int i, int j) {
    int fi = find(i), fj = find(j);
    if (fi != fj) {
        if (w[fi] < w[fj]) {
            v[fi] = fj;
            w[fj] += w[fi];
        } else {
            v[fj] = fi;
            w[fi] += w[fj];
        }
    }
}

void readint(int& ret){
    ret = 0;
    char r;
    bool start=false,neg=false;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(neg) ret *= -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, q;
    readint(n);
    readint(q);
    v.resize(n, -1);
    w.resize(n, 1);
    char op;
    int a, b;
    for (int i = 0; i < q; ++i) {
        op = getchar();
        readint(a);
        readint(b);
        if (op == '=') {
            join(a, b);
        } else {
            if (find(a) == find(b)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
}