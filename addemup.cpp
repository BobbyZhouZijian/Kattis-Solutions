#include <iostream>
#include <vector>
#include <set>

using namespace std;

char mapper[10] = {'0', '1', '2', 0, 0, '5', '9', 0, '8', '6'};

int turn_upside_down(string s) {
    string new_s = "";
    bool can = true;
    for (char ch : s) {
        char inverted = mapper[ch - '0'];
        if (inverted == 0) {
            can = false;
            break;
        }
        new_s = inverted + new_s;
    }
    if (!can) return -1;
    return stoi(new_s);
}

int main() {
    int n, sum;
    cin >> n >> sum;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    set<int> m, seen;
    for (int i = 0; i < n; ++i) {
        int cur = nums[i];
        string s = to_string(cur);
        int inverted = turn_upside_down(s);
        m.insert(cur);
        if (inverted != -1) {
            m.insert(inverted);
            if (inverted + cur == sum) {
                if (seen.find(inverted) != seen.end()) {
                    cout << "YES" << endl;
                    return 0;
                }                    
                seen.insert(cur);
                seen.insert(inverted);
            }
        }
    }

    for (int it : m) {
        int comp = sum - it;
        if (m.find(comp) == m.end() || turn_upside_down(to_string(it)) == comp) continue;
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
}