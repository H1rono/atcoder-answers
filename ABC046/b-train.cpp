#include <cmath>
#include <iostream>
#include <vector>

using std::size_t;

int main() {
    size_t n, k;
    std::cin >> n >> k;
    size_t ans = pow(k - 1, n - 1) * k;
    std::cout << ans << std::endl;
}
