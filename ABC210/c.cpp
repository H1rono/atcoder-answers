#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <utility>
#include <cstdint>

using u64 = std::uint64_t;


int main() {
    int ln, choose_num;
    std::cin >> ln >> choose_num;

    int max_color_num = 0, color_num = 0;
    std::vector<u64> colors;
    std::map<u64, int> having_colors;

    int tail = 0;

    for (int i = 0; i < ln; ++i) {
        u64 color;
        std::cin >> color;
        colors.emplace_back(color);
        int & count = having_colors[color];
        count++;
        color_num += count == 1;
        if (i - tail >= choose_num) {
            int & count_ = having_colors[colors[i - choose_num]];
            count_--;
            color_num -= count_ == 0;
        }
        if (color_num > max_color_num) max_color_num = color_num;
    }

    std::cout << max_color_num << std::endl;
}

