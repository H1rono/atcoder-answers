#include <iostream>
#include <cstdint>
#include <vector>

struct Point {
    int x, y;

    Point(int x, int y): x(x), y(y) {}

    inline int mag_sq() {
        return x * x + y * y;
    }
};

inline Point operator+(const Point &lh, const Point &rh) {
    return Point(lh.x + rh.x, lh.y + rh.y);
}

inline Point operator-(const Point &lh, const Point &rh) {
    return Point(lh.x - rh.x, lh.y - rh.y);
}

inline bool operator==(const Point &lh, const Point &rh) {
    return lh.x == rh.x && lh.y == rh.y;
}

inline bool operator!=(const Point &lh, const Point &rh) {
    return lh.x != rh.x || lh.y != rh.y;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<Point> mag_m_points{};
    auto reg_point = [&](const Point &p) -> void {
        mag_m_points.push_back(p);
        if (p.x != p.y) {
            mag_m_points.emplace_back(p.y, p.x);
        }
    };
    for (int x = 0; x < n; ++x)
    for (int y = x; y < n; ++y) {
        Point p{x, y};
        if (p.mag_sq() != m) {
            continue;
        }
        reg_point(p);
        reg_point(Point{-p.x,  p.y});
        reg_point(Point{ p.x, -p.y});
        reg_point(Point{-p.x, -p.y});
    }
    std::vector<std::vector<int>*> dists(n, nullptr);
    for (int i = 0; i < n; ++i) {
        dists[i] = new std::vector<int>(n, -1);
    }
    dists[0]->at(0) = 0;
    std::vector<Point> que{Point{0, 0}};
    for (size_t i = 0; i < que.size(); ++i) {
        const Point &p = que[i];
        int ndist = dists[p.x]->at(p.y) + 1;
        for (const Point &dp : mag_m_points) {
            Point np = p + dp;
            if (
                (np.x >= 0 && np.x < n)
             && (np.y >= 0 && np.y < n)
             && dists[np.x]->at(np.y) < 0
            ) {
                dists[np.x]->at(np.y) = ndist;
                que.push_back(np);
            }
        }
    }
    for (const auto &row : dists) {
        std::cout << row->at(0);
        for (size_t i = 1; i < row->size(); ++i) {
            std::cout << ' ' << row->at(i);
        }
        std::cout << std::endl;
        delete row;
    }
}
