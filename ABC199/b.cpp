#include <iostream>
#include <algorithm>

int main() {
    int n, a_max = 0, b_min = 1001;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        a_max = std::max(a_max, a);
    }
    for (int i = 0; i < n; ++i) {
        int b;
        std::cin >> b;
        b_min = std::min(b_min, b);
    }
    std::cout << std::max(0, b_min - a_max + 1) << std::endl;
}

