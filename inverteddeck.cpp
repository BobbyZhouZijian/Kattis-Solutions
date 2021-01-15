#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;

    vector<pair<int, pair<int, int>>> arr;
    int last = 0;
    int start = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (x!=last) {
            arr.push_back({last, {start,i-1}});
            last=x;
            start=i;
        }
    }
    arr.push_back({last,{start,n}});
    arr.push_back({INT_MAX, {n+1,n+1}});

    int sz = arr.size();

    int st=-1;
    int end=-1;
    bool possible=true;

    for (int i=0; i+1<sz; ++i) {
        if (arr[i].first>arr[i+1].first) {
            if (st==-1) st=i;
            else if (end!=-1) {
                possible=false;
                break;
            }
        } else if (st!=-1 &&end==-1) {
            end=i;
        }
    }

    if (st==-1&&end==-1) cout << "1 1" << endl;
    else if (!possible || arr[end].first < arr[st-1].first || arr[end+1].first < arr[st].first) {
        cout << "impossible" << endl;
    } else {
        cout << arr[st].second.first << " " << arr[end].second.second << endl;
    }
}
