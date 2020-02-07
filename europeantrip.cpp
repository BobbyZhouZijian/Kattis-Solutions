#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double distance(double x, double y, double x1, double y1) {
	return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}

double cal(double x, double y, double x1, double y1, double x2, double y2, double x3, double y3) {
	return distance(x, y, x1, y1) + distance(x, y, x2, y2) + distance(x, y, x3, y3);
}

int main() {
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	double bx = (x1 + x2 + x3) / 3.0;
	double by = (y1 + y2 + y3) / 3.0;

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	double cur_dis = cal(bx, by, x1, y1, x2, y2, x3, y3);

	double t = 1000;
	bool found = false;
	while(t > 1e-5) {
		found = false;
		for(int i = 0; i < 4; ++i) {
			double nx = bx + dx[i] * t;
			double ny = by + dy[i] * t;

			double new_dis = cal(nx, ny, x1, y1, x2, y2, x3, y3);
			if(new_dis < cur_dis) {
				found = true;
				cur_dis = new_dis;
				bx = nx;
				by = ny;
			}
		}

		if(!found) t /= 2.0;
	}

	cout << fixed << setprecision(5) << bx << " " << by;
}