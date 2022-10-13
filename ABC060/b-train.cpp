#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    // judge whether there is `n, k` such that `a * n = b * k + c`
    int gcd_abc = gcd(gcd(a, b), c);
    a /= gcd_abc;
    b /= gcd_abc;
    c /= gcd_abc;
    if (gcd(a, b) > 1) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }
}
