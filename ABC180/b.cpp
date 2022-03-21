#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

auto main() -> int {
    int N;
    double d;
    cin >> N;
    cout << fixed << setprecision(16);
    vector<double> X(N);
    for (double &x : X) {
        cin >> x;
    }
    d = 0;
    for (auto &x : X) {
        d += abs(x);
    }
    cout << d << endl;
    d = 0;
    for (auto &x : X) {
        d += pow(x, 2);
    }
    cout << sqrt(d) << endl;
    d = 0;
    for (auto &x : X) {
        d = d > abs(x) ? d : abs(x);
    }
    cout << d << endl;
}