#include <iostream>
#include <vector>

using namespace std;


int main() {
	
	int rows[10] = {0}, cols[10] = {0}, d1[20] = {0}, d2[20] = {0};
	bool valid = true;
	int num = 0;

	for (int i = 0; i < 8; ++i) {
		string s;
		cin >> s;


		if (!valid) continue;

		for (int j = 0; j < 8; ++j) {
			if (s[j] == '*') {
				num++;
				if (rows[i] == 1 || cols[j] == 1 || d1[10 + i - j] == 1 || d2[i + j] == 1) {
					valid = false;
					break;
				}

				rows[i] = 1;
				cols[j] = 1;
				d1[10 + i - j] = 1;
				d2[i + j] = 1;
			}

			else continue;
		}
	}	

	if(num != 8) valid = false;

	cout << (valid ? "valid" : "invalid"); 

}