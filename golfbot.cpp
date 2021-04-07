#include <bits/stdc++.h>

using namespace std;
const double PI = acos(-1);
const int maxn = 800010;
typedef complex <double> Complex;
 
void rader(Complex *y, int len) {
    for(int i = 1, j = len / 2; i < len - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        int k = len / 2;
        while(j >= k) {j -= k; k /= 2;}
        if(j < k) j += k;
    }
}
void fft(Complex *y, int len, int op) {
    rader(y, len);
    for(int h = 2; h <= len; h <<= 1) {
        double ang = op * 2 * PI / h;
        Complex wn(cos(ang), sin(ang));
        for(int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for(int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if(op == -1) for(int i = 0; i < len; i++) y[i] /= len;
}
 
Complex x1[maxn], x2[maxn];
int n, q, a[maxn];
 
int main() {
    memset(a, 0, sizeof(a));
    scanf("%d",&n);
    int len1 = 0;
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        a[x]=1;
        len1 = max(len1, x);
    }
    len1++;
    int len=1;
    while(len<len1*2) len<<=1;
    a[0] = 1;
    for(int i=0; i<len1; i++) {
        x1[i] = Complex(a[i], 0);
        x2[i] = Complex(a[i], 0);
    }
    fft(x1, len, 1);
    fft(x2, len, 1);
    for(int i=0; i<len; i++)
        x1[i] = x1[i]*x2[i];
    fft(x1, len, -1);
    scanf("%d", &q);
    int ans = 0;
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d",&x);
        if (x1[x].real() > 0.1) ans++;
    }
    printf("%d\n", ans);
}
