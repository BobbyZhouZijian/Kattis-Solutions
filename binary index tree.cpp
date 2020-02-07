#include <iostream>
using namespace std;

//make a binary index tree
int bit[], n;

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i = i & -i;
    }

    return s;
}

int add(int add, int i) {
    while (i < n) {
        bit[i] += add;
        i += i & -i;
    }
}

int main() {
    //...
}