#include <iostream>
using namespace std;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

bool is_pal(int num) {
    int new_num = 0;
    int cur_num = num;
    while(cur_num) {
        int digit = cur_num % 10;
        new_num = new_num * 10 + digit;
        cur_num /= 10;
    }

    return new_num == num;
}

int main() {
    fast();
    
    int n; cin >> n;
    while(n--) {
        int num; cin >> num;

        int add = num;
        while(add < 1000000 && !is_pal(add)) add++;
        int minus = num;
        while(100000 <= minus && !is_pal(minus)) minus--;

        if(!is_pal(add) || add >= 1000000) cout << minus << endl;
        else if (!is_pal(minus) || minus < 100000) cout << add << endl;
        else {
            //compare diff
            int diff1 = add - num;
            int diff2 = num - minus;
            cout << (diff1 < diff2 ? add : minus) << endl;
        }
    }
}