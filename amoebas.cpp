#include<bits/stdc++.h>
using namespace std;

int r, c, cnt = 0;
int arr[105][105] = {0};


void dfs(int i, int j) {
    if (arr[i][j] != 1) return;
    if (i < 0 || i > r + 1 || j < 0 || j > c + 1) return;
    arr[i][j] = 0;

    dfs(i+1,j);
    dfs(i+1,j+1);
    dfs(i+1,j-1);
    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i-1,j+1);
    dfs(i-1,j);
    dfs(i-1,j-1);
}

int main() {
    scanf("%d%d", &r, &c); 
    char ch;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            scanf(" %c", &ch);
            if (ch == '#')
                arr[i][j] = 1;
        }
    } 

    for (int i = 0; i <= r + 1; ++i) {
        for (int j = 0; j <= c + 1; ++j) {
            if (arr[i][j] == 1) {
                dfs(i,j);
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
}
