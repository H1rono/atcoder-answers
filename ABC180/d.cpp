#include <iostream>

using namespace std;
using L = long long;

auto main() -> int {
    L X, Y, A, B, exp = 0;
    cin >> X >> Y >> A >> B;
    while (X < Y) {
        L tmp = X * A;
        if (tmp >= X + B) {
            break;
        }
        X = tmp;
        ++exp;
    }
    exp += (Y - X - 1) / B;
    cout << exp << endl;
}