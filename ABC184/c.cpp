#include <iostream>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;
using pint = pair<int, int>;


bool iscross(int a, int b, int c, int d) {
    return (
        a + b == c + d
        || a - b == c - d
    );
}


bool isnear(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d) <= 3;
}


bool cango(int a, int b, int c, int d) {
    return iscross(a, b, c, d) || isnear(a, b, c, d);
}


int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool p = false;
    if (a == c && b == d) {
        cout << 0;
        goto END;
    }
    if (cango(a, b, c, d)) {
        cout << 1;
        goto END;
    }
    p = ((a+c)&1) == ((b+d)&1);
    for (int i = -3; i <= 3; ++i) for (int j = -3; j <= 3; ++j) {
        if (p) { break; }
        if (iscross(i, j, 0, 0) || !isnear(i, j, 0, 0)) { continue; }
        p = cango(a + i, b + j, c, d);
    }
    if (p) {
        cout << 2;
        goto END;
    }
    cout << 3;
    END:
    cout << endl;
}