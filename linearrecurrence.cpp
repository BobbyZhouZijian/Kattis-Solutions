#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

struct Matrix {
    ll arr[45][45];
};
Matrix mat;
ll vec[45];

ll mod(ll a, ll m) {
    return ((a%m)+m) % m;
}

Matrix matMult(Matrix a, Matrix b, ll m) {
    Matrix ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans.arr[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (a.arr[i][k] == 0) continue;
            for (int j = 0; j < n; ++j) {
                ans.arr[i][j] += mod(a.arr[i][k], m) * mod(b.arr[k][j], m);
                ans.arr[i][j] = mod(ans.arr[i][j], m);
            }
        }
    }
    return ans;
}

Matrix matPow(Matrix a, ll p, ll m) { 
    Matrix ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans.arr[i][j] = (i==j);
        }
    }

    while (p > 0) {
        if (p % 2 == 1) {
            ans = matMult(ans, a, m);
        }
        a = matMult(a, a, m);
        p /= 2;
    }
    return ans;
}

ll getRes(Matrix a, ll vec[], ll m) {
    ll ans = 0; 
    for (int i =0; i < n; ++i) {
        ans += mod(a.arr[n-1][i] * vec[i], m);
        ans = mod(ans, m);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    n++;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat.arr[i][j] = (i == j + 1);
        }
    }
    mat.arr[0][0] = 1;
    
    vec[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> mat.arr[1][i];
    }
    for (int i = n-1; i >= 1; --i) {
        cin >> vec[i];
    }

    int q;
    cin >> q;
    ll t, m;
    for (int i = 0; i < q; ++i) {
        cin >> t >> m;
        Matrix ans = matPow(mat, t, m);
        cout << getRes(ans, vec, m) << '\n';
    }
}
