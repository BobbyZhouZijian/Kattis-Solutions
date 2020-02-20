#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <set>
#include <queue>
using namespace std;

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    
    map<int, vector<int>> group2item;
    int minGroup = m;
    
    for (int i = 0; i < group.size(); i++) {
        if (group[i] == -1)
            group[i] = minGroup ++;
        
        group2item[group[i]].push_back(i);
    }
    
    
    map<int, set<int>> gm;
    map<int, int> gin;
    map<int, set<int>> indm;
    map<int, int> indin;
    
    for (int i = 0; i < beforeItems.size(); i++) {
        int to = group[i];
        
        for (auto p : beforeItems[i]) {
            int from = group[p];
            
            if (from == to) {
                indm[p].insert(i);
                indin[i] ++;
            }
            
            else {
                if (gm[from].count(to) == 0) {
                    gm[from].insert(to);
                    gin[to]++;
                }
            }
        }
    }
    
    queue<int> q;
    vector<int> gans;
    
    for (int i = 0; i < minGroup; i++) {
        if (gin[i] == 0){
            q.push(i);
            gans.push_back(i);
        }
    }
    
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        
        for (int to : gm[from]) {
            gin[to]--;
            
            if (gin[to] == 0) {
                q.push(to);
                gans.push_back(to);
            }
        }
    }
    
    if (gans.size() != minGroup)
        return {};
    
    vector<int> ans;
    
    for (auto id : gans) {
        auto& items = group2item[id];
        
        int count = 0;
        
        for (auto i : items) {
            if (indin[i] == 0) {
                q.push(i);
                ans.push_back(i);
                count++;
                
            }
        }
        
        while (!q.empty()) {
            int from = q.front();
            q.pop();
            
            for (auto to : indm[from]) {
                indin[to]--;
                
                if (indin[to] == 0) {
                    q.push(to);
                    ans.push_back(to);
                    count ++;
                }
            }
        }
        
        if (count != items.size())
            return {};
    }
    
    return ans;
    
    
};


int main() {
    
    string s;
    while (getline(cin, s)) {
        if (s == "")
            return 0;
        
        stringstream in(s);
        int x;
        in >> x;

        double sq = sqrt(x);
        int perfect = 1;
        
        for (int i = 2; i <= sq; i++) {
            if (x % i == 0) {
                if (i != sq)
                    perfect += (i + x / i);
                else
                    perfect += i;
            }
        }
        
        if (perfect == x)
            cout << x << " perfect" << endl;
        else {
            if (abs(x - perfect) <= 2)
                cout << x << " almost perfect" << endl;
            
            else
                cout << x << " not perfect" << endl;
        }
    }
}
