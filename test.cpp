#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n = 2147483640;
    for(int i = 0; i < 10; ++i) {
        n++;
    }
    printf("n = %d\n", INT_MAX + INT_MIN);
}


