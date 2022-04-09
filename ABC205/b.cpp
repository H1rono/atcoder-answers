#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<bool> flags(n, false);
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        flags[num - 1] = true;
    }
    for (bool flag : flags) {
        if (!flag) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}