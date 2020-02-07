# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int case_ = 1;

    while (n-- > 0) {
        int l, k, s;

        cin >> l >> k >> s;

        vector<int> freq(s, 0);
        for (int i = 0; i < s; i++) {
            cin >> freq[i];
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int pos = 1;
        ll count = 0;
        int occupy = 0;

        for (auto i : freq) {
            count += pos * i;
            occupy++;

            if (occupy == k) {
                pos++;
                occupy = 0;
            }
        }

        cout << "Case #" << case_ << ": " << count << endl;
        case_++;
    }
}

