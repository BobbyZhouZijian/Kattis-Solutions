#include <bits/stdc++.h>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
}

int N;

class PQueue {

private:
    int size;
    vector<pair<int, int>> infects;
    unordered_map<string, int> m1;
    unordered_map<int, string> m2;

    bool greater(int x, int y) {
        if (infects[x].first > infects[y].first) return true;
        return (infects[x].first == infects[y].first && infects[x].second > infects[y].second);
    }
    
    int parent(int& x) {
        return x >> 1;
    }

    int left(int& x) {
        return x << 1;
    }

    int right(int& x) {
        return (x << 1) + 1;
    }


    void swap_ele(int x, int y) {
        if (x == y) return;
        string s = m2[x];
        m2[x] = m2[y];
        m2[y] = s;

        m1[m2[x]] = x;
        m1[m2[y]] = y;

        swap(infects[x], infects[y]);
    }

    void bubble_up(int idx) {
        while (idx > 1 && greater(idx, parent(idx))) {
            swap_ele(idx, parent(idx));
            idx >>= 1;
        }
    }

    void bubble_down(int idx) {
        while (left(idx) <= size) {
            int next = idx;
            if (greater(left(idx), idx)) {
                next = left(idx);
            }
            if (right(idx) <= size && greater(right(idx), next)) {
                next = right(idx);
            }
            if (next == idx) return;
            swap_ele(idx, next);
            idx = next;
        }
    }

public:

    PQueue() {
        infects.clear();
        infects.push_back({0,0});
        size = 0;
    }

    void push(string& name, int& infec, int& n) {
        infects.emplace_back(infec, n);
        m1.emplace(name, ++size);
        m2.emplace(m1[name], name);
        bubble_up(size);
    }

    void update(string& name, int& amt) {
        int idx = m1[name];
        infects[idx].first += amt;
        bubble_up(idx);
    }

    void remove(string& name) {
        int idx = m1[name];
        if (idx != size) {
            swap_ele(idx, size);
            if (greater(size--, idx)) {
                bubble_down(idx);
            } else {
                bubble_up(idx);
            }
        } else {
            --size;
        }
        infects.pop_back();
        m1.erase(name);
        m2.erase(size+1);
    }

    string get() {
        return size > 0 ? m2[1] : "The clinic is empty";
    }
};


void solve() {
    int q, infec; string name;
    PQueue pq;
    while (N--) {
        cin >> q;

        switch(q) {
            case 0:
                cin >> name >> infec;
                pq.push(name, infec, N);
                break;
            case 1:
                cin >> name >> infec;
                pq.update(name, infec);
                break;
            case 2:
                cin >> name;
                pq.remove(name);
                break;
            case 3:
                cout << pq.get() << "\n";
                break;
        }
    }
}

int main() {
    fast();

    cin >> N;
    solve();
    return 0;
}
