#include <iostream>
using namespace std;

bool is_pal(int a, int i) {
    int s[10000], j = 0;

    while(a > 0) {
        s[j++] = a % i;
        a /= i; 
    }

    for(int k = 0; k <= j / 2; ++k) {
        if(s[k] != s[j - k - 1]) return false;
    }

    return true;
}

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    int ans = 0;

    while(a <= b) {
        bool ok = true;
        for(int i = 2; i <= k; ++i) {
            if(!is_pal(a, i)) {
                ok = false;
                break;
            }
        }
        a++;
        if(ok) ans++;
    }

    cout << ans;
}