#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <utility>

using position = std::pair<int, int>;

position operator+(const position& lhs, const position& rhs) {
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}

position operator-(const position& lhs, const position& rhs) {
    return {lhs.first - rhs.first, lhs.second - rhs.second};
}

std::optional<position> solve(int h, int w, const std::vector<std::string>& grid) {
    std::vector<std::vector<bool>> seen(h, std::vector<bool>(w, false));
    position current{0, 0};
    while (true) {
        seen[current.first][current.second] = true;
        position next = current;
        switch (grid[current.first][current.second]) {
            case 'R':
                next.second++;
                break;
            case 'L':
                next.second--;
                break;
            case 'U':
                next.first--;
                break;
            case 'D':
                next.first++;
                break;
        }
        if (next.first < 0 || next.first >= h || next.second < 0 || next.second >= w) {
            return current + position{1, 1};
        }
        if (seen[next.first][next.second]) {
            return std::nullopt;
        }
        current = next;
    }
}

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> grid(h);
    for (int i = 0; i < h; i++) {
        std::cin >> grid[i];
    }
    auto ans = solve(h, w, grid);
    if (ans) {
        auto ans_v = ans.value();
        std::cout << ans_v.first << " " << ans_v.second << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
}
