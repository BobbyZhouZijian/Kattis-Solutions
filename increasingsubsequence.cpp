#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> solve(vector<int>& arr) {
    map<int, int> numToLen;
    map<int, vector<int>> numToArr;
    int n = arr.size();
    int maxLen = 0;
    vector<int> lenToNum = vector<int>(n + 10, 0);
    numToLen[arr[0]] = 1;
    numToArr[arr[0]] = {arr[0]};
    lenToNum[1] = arr[0];
    for (int i = 1; i < n; ++i) {
        int cur = arr[i];
        // find greatest existing key
        auto lower_ptr = numToLen.lower_bound(cur - 1);
        int lower = 0;
        int len = 1;
        if (lower_ptr == numToLen.end()) lower_ptr--;
        while (lower_ptr != numToLen.begin() && lower_ptr->first >= cur) lower_ptr--;
        if (lower_ptr->first < cur) {
            lower = lower_ptr->first;
            len = lower_ptr->second + 1;
        }
        maxLen = max(maxLen, len);
        vector<int> copy = numToArr[lower];
        copy.push_back(cur);
        if (lenToNum[len]) {
            numToArr.erase(lenToNum[len]);
            numToLen.erase(lenToNum[len]);
        }
        numToArr[cur] = copy;
        numToLen[cur] = len;
        lenToNum[len] = cur;
    }
    int num = lenToNum[maxLen];
    return numToArr[num];
}

int main() {
    // io
    int n;
    while (1) {
        cin >> n;
        if (!n) {
            break;
        }
        vector<int> arr = vector<int>();
        for (int i = 0; i < n; ++i) {
            int cur;
            cin >> cur;
            arr.push_back(cur);
        }

        vector<int> res = solve(arr);

        cout << res.size() << " ";
        for (int i : res) cout << i << " ";
        cout << endl;
    }
}
