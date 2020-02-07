#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

vector<int> digits;
set<int> primes;
int numleft;

bool is_prime(int x) {
    if (x == 1 || x == 0)
        return false;

    if (x == 2)
        return true;

    double sq = sqrt(x);

    for (int i = 2; i <= sq; i++) {
        if (x % i == 0)
            return false;
    }

    return true;
}

void process(int cur) {
    if (is_prime(cur))
        primes.insert(cur);
    
    if (numleft == 0)   return;
    
    for (int i = 0; i < 10; i++) {
        if (digits[i] > 0) {
            cur = cur * 10 + i;
            numleft --;
            digits[i]--;

            process(cur);

            numleft ++;
            digits[i]++;
            cur /= 10;
        }
    }

    return;
}



int main() {
    int n;
    cin >> n;

    while (n-- > 0) {
        string s;
        cin >> s;

        digits.clear();
        digits.resize(10, 0);
        numleft = 0;
        primes.clear();

        for (auto i : s) {
            digits[i - '0']++;
            numleft ++;
        }
        int cur = 0;
        process(cur);

        cout << primes.size() << endl;
    }

    return 0;
}