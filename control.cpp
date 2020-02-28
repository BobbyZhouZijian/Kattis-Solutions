#include <iostream>
#include <vector>
#include <set>
using namespace std;

/* global names */
int m, k, ans = 0;
vector<int> f(500000, -1);

/* union finder */
int find(int x) {
    if (f[x] <= -1) return x;
    return f[x] = find(f[x]);
}

void join(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        f[a] += f[b];
        f[b] = a;
    } 
}

int size_finder(int x) {
    int a = find(x);
    return -f[a];
}

/* fast io */
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

/* main */
int main() {
    fast();

    cin >> m;
    while(m--) {
        cin >> k;
        set<int> dist;
        vector<int> inputs(k);
        for(auto& i : inputs) {
            cin >> i;
            i = find(i);
            dist.insert(i);
        }

        int count = 0;
        for(auto& i : dist) {
            count += size_finder(i);
        }

        /* debug
        cout << "k cin: " << k << endl;
        cout << "dist: ";
        for(auto i : dist) cout << i << " ";
        cout << "\n" << "inputs: ";
        for(auto i : inputs) cout << i << " ";
        cout << "\n\n";
        */
       
        if (count == k) {
            ans++;
            for (int i = 1; i < k; ++i) {
                join(inputs[0], inputs[i]);
            }
        }
    }

    cout << ans;
}