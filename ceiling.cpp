#include <bits/stdc++.h>
using namespace std;

int N, K;
int ans = 0;

struct node {
    int val;
    node *left;
    node *right;

    node(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(int x, node *root) {
    while (root) {
        if (x < root->val) {
            if (!root->left) {
                root->left = new node(x);
                return;
            }
            root = root->left;
        } else {
            if (!root->right) {
                root->right = new node(x);
                return;
            }
            root = root->right;
        }
    }
}

bool eq(node *a1, node *a2) {
    if (!a1 && !a2) {
        return true;
    }
    if (a1 && a2) {
        return eq(a1->left, a2->left) && eq(a1->right, a2->right);
    }
    return false;
}

void solve() {
    vector<node*> v;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        node *root = new node(x);
        for (int j = 1; j < K; ++j) {
            int x; cin >> x;
            insert(x, root);
        }

        bool rep = false;
        for (node *n : v) {
            if (eq(n, root)) {
                rep = true;
                break;
            }
        }
        if (!rep) {
            v.push_back(root);
            ans++;
        }
    }
    cout << ans << endl;
}

int main (){ 
    cin >> N >> K;
    solve();
}