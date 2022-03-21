#include <iostream>
#include <iomanip>

int main() {
    double sx, sy, gx, gy, ans;
    std::cin >> sx  >> sy >> gx >> gy;
    ans = sx + sy * (gx - sx) / (gy + sy);
    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
}