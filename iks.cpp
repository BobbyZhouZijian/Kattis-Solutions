#include <iostream>
#include <map>
#include <vector>
#define N 1000005
using namespace std;

int primes[N] = {0};
long n;
map<int, vector<int> > m;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

void initialize() {
    for(int i = 2; i <= (N - 5) / 2; ++i) {
        if(primes[i]) continue;
        int k = 2;
        while(k * i <= N - 5) {
            primes[i * k] = 1;
            k++;
        }
    }
}

void add(int num) {
    int index = 2, count = 0;
    
    while(num >= index && index < N) {
        while(primes[index]) index++;
        if(num % index == 0) {
            num /= index;
            count++;
        }
        else {
            if(count) m[index].push_back(count);
            count = 0;
            index++;
        }
    }
    if(count) m[index].push_back(count);
}

int main() {
    fast();
    initialize();

    /*
    //debug initialize
    for(int i = 0; i < 50; ++i) {
        if(!primes[i]) cout << i << " "; 
    }
    cout << "\n";
    */

    cin >> n;
    int cur;
    for(int i = 0; i < n; ++i) {
        cin >> cur;
        add(cur);
    }

    long ans = 1l, op = 0l;
    for(auto &p : m) {

        long ave = 0l;
        for(long i : p.second) ave += i;
        ave /= n;
        for(long i : p.second) op += (ave - i > 0l ? ave - i : 0l);
        for(long j = p.second.size(); j < n; ++j) op += ave;

        for(int k = 0; k < ave; ++k) ans *= p.first;

        /*
        //debug
        cout << ans << " " << p.first << " ";
        for(int i : p.second) cout << i << " ";
        cout << "\n";
        */
    }

    cout << ans << " " << op;

    return 0;
}