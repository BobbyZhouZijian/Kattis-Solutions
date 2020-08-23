#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> ind(n, {0, 0});
    pair<int, int> group = {0, 0};
    string command;
    int index, num;

    for (int i = 1; i <= q; ++i) {
        cin >> command;
        if (command == "SET") {
            cin >> index >> num;
            ind[index - 1] = {num, i};
        } else if (command == "RESTART") {
            cin >> num;
            group = {num, i};
        } else {
            cin >> index;
            pair<int, int>& cur = ind[index - 1];
            if (cur.second < group.second) {
                cout << group.first << endl;
            } else {
                cout << cur.first << endl;
            }
        } 
    }
}