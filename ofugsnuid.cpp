#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<string> res;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        res.push_back(s);
    }
    for (int i = n - 1; i >= 0; --i) cout << res[i] << endl;
}