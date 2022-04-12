#include <iostream>
#include <vector>
#include <cstdint>

using u32 = std::uint32_t;

int main() {
    int n;
    std::cin >> n;
    std::vector<u32> as, bs;
    for (int i = 0; i < n; ++i) {
        u32 a_i;
        std::cin >> a_i;
        as.push_back(a_i);
    }
    for (int i = 0; i < n; ++i) {
        u32 b_i;
        std::cin >> b_i;
        bs.push_back(b_i);
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        if (as[i] == bs[j]) {
            (i == j ? ans1 : ans2)++;
        }
    }
    std::cout << ans1 << '\n' << ans2 << std::endl;
}