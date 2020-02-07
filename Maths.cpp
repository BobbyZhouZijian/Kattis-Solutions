#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b != 0) return gcd(a % b, b);
    else return a;
}

set<int> prime_fact(int x) {
    set<int> ans;

    while (x > 1) {
        bool changed = false;
        for (int i = 2; i <= sqrt(x); ++i) {
            if (x % i == 0) {
                ans.insert(i);
                x /= i;
                changed = true;
                break;
            }
        }

        if (!changed)
            break;
    }

    return ans;
}

int main() {
    int x;
    cin >> x;

    auto out = prime_fact(x);

    for(auto num : out) cout << num << endl;
}