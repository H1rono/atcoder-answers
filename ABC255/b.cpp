#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
public:
    double x, y;

    Point(double x, double y) : x(x), y(y) {}

    double mag() {
        return std::sqrt(x * x + y * y);
    }
};

Point operator + (const Point & lh, const Point & rh) {
    return Point{
        lh.x + rh.x,
        lh.y + rh.y
    };
}

Point operator - (const Point & lh, const Point & rh) {
    return Point{
        lh.x - rh.x,
        lh.y - rh.y
    };
}

struct Person {
public:
    bool has_light;
    Point coord;

    Person(bool l, Point c) : has_light(l), coord(c) {}
    Person(bool l, double x, double y) : has_light(l), coord(x, y) {}
};

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<bool> have_light(n, false);
    for (int i = 0; i < k; ++i) {
        int l;
        std::cin >> l;
        have_light[l - 1] = true;
    }
    std::vector<Person> people{};
    for (int i = 0; i < n; ++i) {
        double x, y;
        std::cin >> x >> y;
        people.emplace_back(have_light[i], Point{x, y});
    }
    double max_dist = 0;
    for (int i = 0; i < n; ++i) {
        const Person & pi = people[i];
        if (pi.has_light) continue;
        double dist = -1;
        for (int j = 0; j < n; ++j) {
            const Person & pj = people[j];
            if (!pj.has_light) continue;
            double d = (pi.coord - pj.coord).mag();
            dist = dist == -1 ? d : std::min(dist, d);
        }
        max_dist = std::max(max_dist, dist);
    }
    std::cout << std::fixed << std::setprecision(18);
    std::cout << max_dist << std::endl;
}
