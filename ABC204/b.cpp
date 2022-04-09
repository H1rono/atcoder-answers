#include <iostream>
#include <algorithm>

int main() {
    int tree_num, ans = 0;
    std::cin >> tree_num;
    for (int i = 0; i < tree_num; ++i) {
        int fruit_num;
        std::cin >> fruit_num;
        ans += std::max(0, fruit_num - 10);
    }
    std::cout << ans << std::endl;
}