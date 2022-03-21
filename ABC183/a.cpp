#include <iostream>

int main() {
    int n; std::cin >> n;
    int ans = n < 0 ? 0 : n;
    std::cout << ans << std::endl;
}