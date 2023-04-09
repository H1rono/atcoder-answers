#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using usize = std::size_t;
using u32 = std::uint32_t;
using i32 = std::int32_t;

int main() {
    usize h, w;
    std::cin >> h >> w;
    std::vector<std::string> room(h);
    for (usize i = 0; i < h; ++i) {
        std::cin >> room[i];
    }
    for (usize r = 0; r < h; ++r) {
        std::string &row = room[r];
        for (usize c = 0; c < w - 1; ++c) {
            if (row[c] == 'T' && row[c + 1] == 'T') {
                row[c] = 'P';
                row[c + 1] = 'C';
            }
        }
        std::cout << row << std::endl;
    }
}
