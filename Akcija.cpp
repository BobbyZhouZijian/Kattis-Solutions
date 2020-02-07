#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    vector<int> books;

    int cases;
    cin >> cases;

    while (cases-- > 0) {
        int n;
        cin >> n;
        books.push_back(n);
    }

    sort(books.begin(), books.end(), greater<int>());

    ll res = 0;
    for (int i = 0; i < books.size(); i++) {
        if ((i + 1) % 3) res += books[i];
    }

    cout << res;
}