//find all 5 digit numbers with the digits given;

#include <iostream>
#include <vector>
using namespace std;

int digits[10] = {0};
vector<int> ans;

void find(int x) {
    if (10000 <= x && x < 100000) {
        ans.push_back(x);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (digits[i] > 0) {
            x = 10 * x + i;
            digits[i]--;
            find(x);
            digits[i]++;
            x /= 10;
        }

        else continue;
    }
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        digits[x]++;
    }

    find(0);
    
    for (int num : ans)    cout << num << endl;

    return 0;
}