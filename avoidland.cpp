#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;

	std::vector<ll> xs;
	std::vector<ll> ys;

	for (ll i = 0; i < n; ++i)
	{
		ll x, y;
		cin >> x >> y;
		x--; y--;
		xs.push_back(x);
		ys.push_back(y);
	}

	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());

	ll summ = 0;

	for (ll i = 0; i < n; i++) {
		summ += abs(xs[i] - i);
		summ += abs(ys[i] - i);
	}

	cout << summ;
	return 0;
}