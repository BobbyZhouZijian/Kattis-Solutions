#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector< vector<char> > grid;

void dfs(int i, int j) {

    grid[i][j] = 'V';

    if (i - 1 >= 0 && (grid[i - 1][j] == 'L' || grid[i - 1][j] == 'C'))  dfs(i - 1, j);
    if (i + 1 < m && (grid[i + 1][j] == 'L' || grid[i + 1][j] == 'C'))  dfs(i + 1, j);
    if (j - 1 >= 0 && (grid[i][j - 1] == 'L' || grid[i][j - 1] == 'C'))  dfs(i, j - 1);
    if (j + 1 < n && (grid[i][j + 1] == 'L' || grid[i][j + 1] == 'C'))  dfs(i, j + 1);

    return;
}

int main() {
    cin >> m >> n;

    grid.resize(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j];
        }
    }

    int c = 0;

    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'L') {
                dfs(i, j);
                c++;
            }
        }
    }

    cout << c << endl;
}