#include <bits/stdc++.h>
using namespace std;

int N, M;
double P;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> N >> M >> P;
    P /= 100;
    vector<double> cranks, backs;
    for (int i = 0; i < N; ++i) {
        double x; cin >> x;
        cranks.push_back(x);
    }
    for (int i = 0; i < M; ++i) {
        double x; cin >> x;
        backs.push_back(x);
    }

    sort(cranks.begin(), cranks.end());
    sort(backs.begin(), backs.end());

    bool can = true;
    vector<double> cadence;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cadence.push_back(cranks[i] / backs[j]);
        }
    }

    sort(cadence.begin(), cadence.end());

    for (int i = 0; i + 1 < cadence.size(); ++i) {
        if (cadence[i+1] / cadence[i] > (1+P)) {
            can = false;
            break;
        }
    }

    if (can) {
        cout << "Ride on!" << endl;
    } else {
        cout << "Time to change gears!" << endl;
    }
}
