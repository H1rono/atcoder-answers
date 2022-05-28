#include <iostream>
#include <string.h>
#include <utility>

int main() {
    int rows, cols;
    std::cin >> rows >> cols;
    std::pair<int, int> start{}, goal{};
    bool start_found = false, goal_found = false;
    for (int r = 0; r < rows; ++r) {
        std::string column;
        std::cin >> column;
        if (!goal_found) for (int c = 0; c < cols; ++c) {
            if (column[c] == 'o') {
                std::pair<int, int> pos{r, c};
                if (start_found) {
                    goal = pos;
                    goal_found = true;
                } else {
                    start = pos;
                    start_found = true;
                }
                if (goal_found) break;
            }
        }
    }
    int ans = std::abs(goal.first - start.first) + std::abs(goal.second - start.second);
    std::cout << ans << std::endl;
}
