#include <iostream>
//#include <vector>
//#include <string>

using namespace std;
using L = long long;

int main() {
    int N;
    L ans = 0, a, b;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        ans += (b - a + 1) * (a + b) / 2;
    }
    cout << ans << endl;
}