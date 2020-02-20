#include <iostream>
#define N 24
using namespace std;

char grid[N][N];
int n;

bool check_row(int k) {
    int b = 0, w = 0;

    for(int i = 0; i < n; ++i) {
        if(i < n - 2 && grid[k][i] == grid[k][i + 1] && grid[k][i + 1] == grid[k][i + 2]) {
            return false;
        }

        if(grid[k][i] == 'W') w++;
        else b++;
    }

    return w == b;
}

bool check_col(int k) {
        int b = 0, w = 0;

    for(int i = 0; i < n; ++i) {
        if(i < n - 2 && grid[i][k] == grid[i + 1][k] && grid[i + 1][k] == grid[i + 2][k]) {
            return false;
        }

        if(grid[i][k] == 'W') w++;
        else b++;
    }

    return w == b;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; ++i) {
        if(!check_col(i) || !check_row(i)) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}