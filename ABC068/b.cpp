#include <iostream>
#include <algorithm>

int solve(int n) {
    int ans = 1;
    while (ans <= n) ans *= 2;
    return std::max(1, ans >> 1);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << solve(n) << std::endl;
}
