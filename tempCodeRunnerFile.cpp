#include <vector>
#include <iostream>
using namespace std;

int main() {

    int arr[4] = {1,1,2,3};
    vector<int> new_array;

    for (int pos = 1; pos < 4; pos++) {
        if (arr[pos] == arr[pos - 1])
            continue;
        
        else {
            new_array.push_back(arr[pos - 1]);

            if (pos == 3)
                new_array.push_back(arr[pos]);
        }
    }



    for (auto i : new_array) {
        cout << i << endl;
    }
}