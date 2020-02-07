#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;


int main() {

    int n, k;
    cin >> n >> k;

    unordered_map< string, set<int> > m;
    vector<int> items;

    for (int i = 0; i < k; ++i) {
        int store;
        string s;
        cin >> store >> s;

        m[s].insert(store);
    }

    vector<string> input;
    int k1;
    cin >> k1;

    for (int i = 0; i < k1; ++i) {
        string item;
        cin >> item;
        input.push_back(item);
    }

    int maxm = 0;
    for (auto item : input) {
        vector<int> rem;

        for (auto store : m[item]) {
            if (store < maxm) {
                rem.push_back(store);
            }
        }

        for (auto i : rem) {
            m[item].erase(i);
        }

        if (!m[item].empty()) {
            maxm = max(*m[item].begin(), maxm);
        }
    }

    int minm = 1 << 30;
    for (int i = input.size() - 1; i >= 0; --i) {
        auto item = input[i];
        vector<int> rem;

        for (auto store : m[item]) {
            if (store > minm) {
                rem.push_back(store);
            }
        }

        for (auto i : rem) {
            m[item].erase(i);
        }

        if (!m[item].empty()) {
            minm = min(*m[item].rbegin(), minm);
        }
    }


    bool none = false;
    bool ambig = false;
    for (auto item : input) {
        if (m[item].empty()) none = true;
        else if (m[item].size() > 1) ambig = true;
    }

    if (none)
        cout << "impossible";
    else if (ambig)
        cout << "ambiguous";
    else
        cout << "unique";
}