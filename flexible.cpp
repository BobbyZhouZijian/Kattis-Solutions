#include <bits/stdc++.h>
using namespace std;

int w, p;
unordered_set<int> s;
int arr[105];

int main() {
    scanf("%d%d",&w,&p);
    arr[0] = 0;
    for (int i = 1; i <= p; ++i) {
        scanf("%d",&arr[i]);
    }
    arr[p+1] = w;
    for (int i = 0; i <= p+1; ++i )
        for (int j = 0; j <= p + 1; ++j) {
            if (i == j) continue;
            s.insert(abs(arr[i] - arr[j]));
        }
    
    vector<int> res;
    for (int x : s) res.push_back(x);
    sort(res.begin(), res.end());
    for (int x : res) printf("%d ", x);
}