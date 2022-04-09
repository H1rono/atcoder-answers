#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int ans = n / 100 + !!(n % 100);
    std::cout << ans << std::endl;
}