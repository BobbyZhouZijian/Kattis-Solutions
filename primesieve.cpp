#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<bool> s(n + 1, true);
    // pre-process
    s[0] = false;
    s[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (!s[i]) continue;
        for (int j = 0; i * i + j * i <= n; ++j) {
            s[i * i + j * i] = false;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += s[i];
    }
    cout << cnt << endl;
    int k;
    for (int i = 0; i < q; ++i) {
        cin >> k;
        cout << s[k] << endl;
    }
}