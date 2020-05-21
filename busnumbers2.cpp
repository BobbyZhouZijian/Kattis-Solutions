#include <iostream>
#include <cmath>
#define N 400000
using namespace std;

int sum[N] = {0}, n;

int main() {
    cin >> n;

    int lim = pow(n, 1.0 / 3.0);
    for(int i = 1; i <= lim; ++i) {
        for(int j = i; j <= lim; ++j) {
            int s = i * i * i + j * j * j;
            if(s <= n) sum[s]++; 
        }
    }

    for(int i = n; i >= 1; --i) {
        if(sum[i] >= 2) {
            cout << i;
            return 0;
        }
    }

    cout << "none";
}