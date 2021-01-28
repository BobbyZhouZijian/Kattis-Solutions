#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

struct HASH {
  size_t operator()(const pair<int,int>&x)const{
    size_t ans=0;
    for(int i=0;i<x.first;i++)
      ans+=x.second;
    return ans;
  }
};

template<typename T>
using ost = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).


void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int n;

int main() {
    fast();
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);

    stack<pair<char, int>> st;
    int k = -1; char p;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == '[' || c == '{' || c == '(') { 
            st.push({c, i});
        } else if (c != ' ') {
            if (st.empty()) {
                k = i;
                p = c;
                ok = false;
                break;
            }
            char l = st.top().first;
            if ((c == '}' && l != '{') ||
                (c == ']' && l != '[') ||
                (c == ')' && l != '(')) {
                k = i;
                p = c;
                ok = false;
                break;
            }

            st.pop();
        }
    }

    if (ok) {
        cout << "ok so far" << endl;
    } else {
        cout << p << ' ' << k << endl;
    }

    return 0;
}
