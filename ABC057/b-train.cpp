#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using i64 = std::int64_t;

struct Point {
    i64 x, y;

    Point() : x(0), y(0) {}
    Point(i64 x, i64 y) : x(x), y(y) {}

    i64 manhattan_distance(const Point &other) const {
        return std::abs(x - other.x) + std::abs(y - other.y);
    }
};

int main() {
    size_t n, m;
    std::cin >> n >> m;
    std::vector<Point> students(n, Point{}), checkpoints(m, Point{});
    for (int i = 0; i < n; ++i) {
        std::cin >> students[i].x >> students[i].y;
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> checkpoints[i].x >> checkpoints[i].y;
    }
    std::vector<size_t> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        size_t min_dist = students[i].manhattan_distance(checkpoints[0]);
        size_t min_index = 0;
        for (int j = 1; j < m; ++j) {
            size_t dist = students[i].manhattan_distance(checkpoints[j]);
            if (dist < min_dist) {
                min_dist = dist;
                min_index = j;
            }
        }
        ans[i] = min_index + 1;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << std::endl;
    }
}
