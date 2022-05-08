#include <iostream>
#include <vector>
#include <cstdint>
#include <utility>

using u32 = std::uint32_t;

int main() {
    u32 n, q;
    std::cin >> n >> q;
    std::vector<u32> nums{}, indices{0};
    for (u32 i = 0; i < n; ++i) {
        nums.emplace_back(i + 1);
        indices.emplace_back(i);
    }
    for (u32 i = 0; i < q; ++i) {
        u32 x;
        std::cin >> x;
        u32 x_i = indices[x];
        u32 y = (x_i == n - 1) ? nums[x_i - 1] : nums[x_i + 1];
        u32 y_i = indices[y];
        std::swap(nums[x_i], nums[y_i]);
        std::swap(indices[x], indices[y]);
    }
    for (u32 i = 0; i < n; ++i) {
        std::cout << (i ? " " : "") << nums[i];
    }
    std::cout << std::endl;
}
