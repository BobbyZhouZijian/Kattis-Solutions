#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void merge(vector<int> &v, vector<int> &v1, vector<int> &v2) {
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    
    while (!v1.empty() || !v2.empty()) {
        if (!v1.empty()) {
            v.push_back(v1.back());
            v1.pop_back();
        }

        if (!v2.empty()) {
            v.push_back(v2.back());
            v2.pop_back();
        }
    }
}

void out_shuffle(vector<int> &v) {
    vector<int> v1;
    vector<int> v2;
    int pos = (v.size() + 1) / 2;

    for (int i = 0; i < v.size(); i++) {
        if (i < pos) {
            v1.push_back(v[i]);
        }

        else {
            v2.push_back(v[i]);
        }
    }

    v.clear();
    merge(v, v1, v2);
}

void in_shuffle(vector<int> &v) {
    vector<int> v1;
    vector<int> v2;
    int pos = v.size() / 2;

    for (int i = 0; i < v.size(); i++) {
        if (i < pos) {
            v1.push_back(v[i]);
        }

        else {
            v2.push_back(v[i]);
        }
    }

    v.clear();
    merge(v, v2, v1);
}

bool solved(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != i)
            return false;
    }

    return true;
}

int main() {
    string s;
    int x;
    cin >> x >> s;

    vector<int> v;

    for (int i = 0; i < x; i++) {
        v.push_back(i);
    }

    int count = 0;
    bool in = (s == "in");

    while (1) {
        count++;

        if (in) {
            in_shuffle(v);
        }

        else
            out_shuffle(v);

        if (solved(v))
            break;
    }

    cout << count;

}