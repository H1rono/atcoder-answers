#include <iostream>
#include <cmath>
#include <vector>

using vec_int = std::vector<int>;

struct Point {
public:
    const long double x, y;
    Point(long double x, long double y): x(x), y(y) {}

    long double mag() {
        return std::sqrt(x * x + y * y);
    }
};

Point operator + (const Point & lh, const Point & rh) {
    return Point(lh.x + rh.x, lh.y + rh.y);
}

Point operator - (const Point & lh, const Point & rh) {
    return Point(lh.x - rh.x, lh.y - rh.y);
}

long double dist(const Point & p1, const Point & p2) {
    return (p1 - p2).mag();
}

struct Circle {
public:
    const Point center;
    const long double radius;
    Circle(long double x, long double y, long double radius)
    : center(x, y), radius(radius) {}
};

long double dist(const Circle & c, const Point & p) {
    return dist(c.center, p) - c.radius;
}

long double dist(const Circle & c1, const Circle & c2) {
    long double center_dist = dist(c1.center, c2.center);
    return center_dist - c1.radius - c2.radius;
}

bool touches(const Circle & c, const Point & p) {
    return dist(c, p) == 0;
}

bool crosses(const Circle & c1, const Circle & c2) {
    long double d = dist(c1.center, c2.center);
    return std::abs(c1.radius - c2.radius) <= d && d <= c1.radius + c2.radius;
}

int main() {
    int n;
    std::cin >> n;
    long double x, y;
    std::cin >> x >> y;
    Point start(x, y);
    std::cin >> x >> y;
    Point goal(x, y);
    vec_int start_touching_circles{}, goal_touching_circles{};
    std::vector<Circle> circles{};
    std::vector<vec_int> graph(n, vec_int{});
    for (int i = 0; i < n; ++i) {
        long double x, y, r;
        std::cin >> x >> y >> r;
        circles.emplace_back(x, y, r);
        const Circle & c_i = circles.back();
        if (touches(c_i, start)) start_touching_circles.push_back(i);
        if (touches(c_i,  goal))  goal_touching_circles.push_back(i);
        for (int j = 0; j < i; ++j) {
            const Circle & c_j = circles[j];
            if (crosses(c_i, c_j)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    std::vector<bool> seen(n, false);
    vec_int queue(start_touching_circles.begin(), start_touching_circles.end());
    for (int i = 0; i < queue.size(); ++i) {
        int v = queue[i];
        if (seen[v]) continue;
        seen[v] = true;
        for (int j : graph[v]) {
            if (seen[j]) continue;
            queue.push_back(j);
        }
    }
    for (int i : goal_touching_circles) {
        if (seen[i]) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
}
