#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a1,b1,c1,d1;
	int a2,b2,c2,d2;
	cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2;

	int sum1 = a1 + b1 + c1 + d1;
	int sum2 = a2 + b2 + c2 + d2;

	if (sum1 > sum2) {
		cout << "Gunnar";
	} else if (sum1 == sum2) {
		cout << "Tie";
	} else {
		cout << "Emma";
	}
	return 0;
}