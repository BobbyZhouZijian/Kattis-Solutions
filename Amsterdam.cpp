# include <iostream>
# include <iomanip>
# include <cmath>
using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

int main() {

    fast();

    int m ,n;
    cin >> m >> n;

    double r;
    cin >> r;

    double x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double nr = (double)r / n;
    double mr = min(y1, y2) * nr * M_PI / m * abs(x2 - x1);

    if (mr > 2 * min(y1, y2) * nr)
        mr = 2 * min(y1, y2) * nr;



    cout <<  setprecision(10) << mr + abs(y2 - y1) * nr;
}