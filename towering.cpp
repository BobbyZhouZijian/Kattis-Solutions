#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,d,e,f,h1,h2;
    cin>>a>>b>>c>>d>>e>>f>>h1>>h2;
    vector<int> v = {a,b,c,d,e,f};
    sort(v.begin(), v.end());
    for (int i = 0; i < 4; ++i) {
        int ta = h1 - v[i];
        int j = i + 1, l = 5;
        while (j < l) {
            if (v[j] + v[l] == ta) {
                cout << v[l] << " " << v[j] << " " << v[i] << " ";
                vector<int> v1;
                for (int m = 0; m < 6; ++m) {
                    if (m != i && m != j && m != l) v1.push_back(v[m]);
                }
                for (int m = 2; m >= 0; --m) {
                    if (m == 0) cout << v1[0];
                    else cout << v1[m] << " ";
                }
                return 0;
            } else if (v[j] + v[l] < ta) j++;
            else l--;
        }
    }
}