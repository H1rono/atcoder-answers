#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {
    int n, x;
    string s;
    cin >> n >> x >> s;
    for (int i = 0; i < n; ++i) {
        int d = s[i] == 'x' ? -1 : 1;
        x = max(0, x + d);
    }
    cout << x << endl;
}