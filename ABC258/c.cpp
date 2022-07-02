#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

using i64 = std::int64_t;

int main() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    i64 head = 0;
    auto at = [&](int i) -> char {
        int m = (head + i) % n;
        return s[m + (m < 0) * n];
    };
    for (int i = 0; i < q; ++i) {
        int t, x;
        std::cin >> t >> x;
        if (t == 1) {
            head -= x;
        } else {
            std::cout << at(x - 1) << std::endl;
        }
    }
}
