#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> tree(r + 10, vector<char>(c + 10, '.'));

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> tree[i][j];
        }
    }

    bool cont = true;
    int ring_num = 1;

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (tree[i][j] == 'T' && (tree[i - 1][j] == '.' || tree[i + 1][j] == '.'
                || tree[i][j - 1] == '.' || tree[i][j + 1] == '.')) {
                tree[i][j] = '0' + ring_num;
            }
        }
    }

    while (cont) {
        ring_num++;
        cont = false;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                char last = '0' + ring_num - 1;
                if (tree[i][j] == 'T' && (tree[i - 1][j] == last
                || tree[i + 1][j] == last || tree[i][j - 1] == last || tree[i][j + 1] == last)) {
                    tree[i][j] = last + 1;
                    cont = true;
                }
            }
        }
    }

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (ring_num < 10) {
                if (tree[i][j] == '.') {
                    cout << "..";
                } else {
                    cout << "." << int(tree[i][j] - '0');
                }
            } else {
                if (tree[i][j] == '.') {
                    cout << "...";
                } else {
                    int cur_num = int(tree[i][j] - '0');
                    if (cur_num >= 10) {
                        cout << "." << cur_num;
                    } else {
                        cout << ".." << cur_num;
                    }
                }
            }
        }
        cout << endl;
    }
}

