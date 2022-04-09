#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if ((c & 1) == 0) {
        a = std::abs(a);
        b = std::abs(b);
    }
    char res = '=';
    if (a < b) {
        res = '<';
    } else if (a > b) {
        res = '>';
    }
    std::cout << res << std::endl;
}