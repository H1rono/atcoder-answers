#include <iostream>
#include <string>
#include <array>

int main() {
    size_t n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    size_t ans = 0;
    for (size_t i = 1; i < n - 1; ++i) {
        std::array<size_t, 26> x_chars{}, y_chars{};
        for (size_t j = 0; j < i; ++j) {
            ++x_chars[s[j] - 'a'];
        }
        for (size_t j = i; j < n; ++j) {
            ++y_chars[s[j] - 'a'];
        }
        size_t kinds = 0;
        for (size_t j = 0; j < 26; ++j) {
            kinds += x_chars[j] > 0 && y_chars[j] > 0;
        }
        ans = std::max(ans, kinds);
    }
    std::cout << ans << std::endl;
}
