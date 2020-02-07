#include <iostream>
using namespace std;

void exgcd(int a, int b, int &x, int&y) {

	if(!b) {
		x = 1; y = 0;
	}

	else {
		exgcd(b, a%b, y, x);
		y -= x*(a/b);
	}

	cout << "when a, b are " << a << " and " << b << ", ";
	cout << "x and y are " << x << " and " << y << endl;
}


int main(int argc, char const *argv[])
{
	int a, b;
	cin >> a >> b;
	int x = 1, y = 1;
	exgcd(a, b, x, y);
	return 0;
}