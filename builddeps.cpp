#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

vector<string> split(string s) {
    vector<string> res;
    string cur = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ':') continue;
        else if (s[i] == ' ') {
            res.push_back(cur);
            cur = "";
        } else {
            cur += s[i];
        }
    }
    if (cur != "") res.push_back(cur);
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    map< string, vector<string> > nb;
    map<string, int> ind;
    string line;
    getline(cin, line);
    while(n--){
        getline(cin, line);
        vector<string> splitted = split(line);
        string u = splitted[0];
        ind[u] = 0;
        for (string v : splitted) {
            if (v == u) continue;
            nb[v].push_back(u);
            ind[u]++;
        }
    }

    getline(cin, line);
    queue<string> q;
    for (auto p : ind) {
        if (p.second == 0 && p.first != line) {
            q.push(p.first);
        }
    }

    while (!q.empty()) {
        string top = q.front(); q.pop();
        for (string next : nb[top]) {
            ind[next]--;
            if (ind[next] == 0 && next != line) {
                q.push(next);
            }
        }
    }

    q.push(line);
    while(!q.empty()) {
        string top = q.front(); q.pop();
        cout << top << endl;
        for (string next : nb[top]) {
            ind[next]--;
            if (ind[next] == 0) {
                q.push(next);
            }
        }
    }
}