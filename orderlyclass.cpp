#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
    cin >> s1 >> s2; 
    s1 = "$" + s1 + "$";
    s2 = "#" + s2 + "#";

    int i = 1, j = s1.length() - 2;
    while (s1[i] == s2[i]) ++i;
    while (s1[j] == s2[j]) --j;

    bool work = 1;
    for (int k = 0; i+k<=j && work; ++k) {
        if (s1[i+k] != s2[j-k]) work = 0;
    }

    int res;
    if (!work) {
        res = 0;
    } else {
        res = 1;
        while (s1[i-res] == s2[j+res]) res++;
    }

    printf("%d\n", res);
}
