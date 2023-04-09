#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using usize = std::size_t;
using u32 = std::uint32_t;
using i32 = std::int32_t;

std::vector<usize> find_char(std::string s, char c) {
    std::vector<usize> ans{};
    for (usize i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;
    {
        std::vector<usize> bs = find_char(s, 'B');
        if ((bs[0] & 1) == (bs[1] & 1)) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    {
        std::vector<usize> rs = find_char(s, 'R');
        usize k = find_char(s, 'K')[0];
        if (!(rs[0] < k && k < rs[1])) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}
