#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n && !cin.eof()) {
        // stack, queue, pq
        bool can[3] = {true, true, true};
        int op, x;
        vector<pair<int, int>> rec;
        for (int i = 0; i < n; ++i) {
            cin >> op >> x;
            rec.push_back({op, x});
        } 

        // stack
        stack<int> st;
        for (auto &it : rec) {
            op = it.first;
            x = it.second;
            if (op == 1) {
                st.push(x);
            } else {
                if (st.empty() || x != st.top()) {
                    can[0] = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }

        queue<int> q;
        // queue
        for (auto &it : rec) {
            op = it.first;
            x = it.second;
            if (op == 1) {
                q.push(x);
            } else {
                if (q.empty() || x != q.front()) {
                    can[1] = false;
                    break;
                } else {
                    q.pop();
                }
            }
        }

        // pq
        priority_queue<int> pq;
        for (auto &it : rec) {
            op = it.first;
            x = it.second;
            if (op == 1) {
                pq.push(x);
            } else {
                if (pq.empty() || x != pq.top()) {
                    can[2] = false;
                    break;
                } else {
                    pq.pop();
                }
            }
        }
        int cnt = can[0] + can[1] + can[2];
        if (!cnt) cout << "impossible" << endl;
        else if (cnt > 1) cout << "not sure" << endl;
        else {
            if (can[0]) cout << "stack" << endl;
            if (can[1]) cout << "queue" << endl;
            if (can[2]) cout << "priority queue" << endl;
        }
    }
}