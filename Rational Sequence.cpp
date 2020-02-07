# include <iostream>
# include <sstream>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    int case_;

    while (n-- > 0) {
        cin >> case_;
        string s;
        cin >> s;

        string s1, s2;

        int pos = 0;
        for (; pos < s.length(); pos++) {
            if (s[pos] == '/')
                break;
        }

        s1 = s.substr(0, pos);
        s2 = s.substr(pos + 1);
        stringstream in1(s1);
        stringstream in2(s2);

        int num, den;

        in1 >> num;
        in2 >> den;

        if (den == 1) {
            cout << case_ << " " << den << "/" << num + 1 << endl;
        }

        else if (den > num) {
            den -=num;
            num += den;

            cout << case_ << " " << num << "/" << den << endl;
        }

        else {
            int count = num / den;
            num = num % den;

            den -= num;
            num += den;

            while (count) {
                count--;
                den += num;
            }

            cout << case_ << " " << num << "/" << den << endl;
        
        }
    }
}