#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct JumpRamp
{
    int x, y, power;
    JumpRamp(int x, int y, int power) : x(x), y(y), power(power) {}
};

struct Edge {
    const JumpRamp * ramp_from;
    const JumpRamp * ramp_to;

    Edge(const JumpRamp * ramp_from, const JumpRamp * ramp_to) : ramp_from(ramp_from), ramp_to(ramp_to) {}

    int cost() const {
        return std::ceil(
            (double)(std::abs(ramp_from->x - ramp_to->x) + std::abs(ramp_from->y - ramp_to->y))
            / (double)ramp_from->power
        );
    }
};

bool operator < (const Edge & lh, const Edge & rh) { return lh.cost() < rh.cost(); }
bool operator <= (const Edge & lh, const Edge & rh) { return lh.cost() <= rh.cost(); }
bool operator > (const Edge & lh, const Edge & rh) { return lh.cost() > rh.cost(); }
bool operator >= (const Edge & lh, const Edge & rh) { return lh.cost() >= rh.cost(); }
bool operator == (const Edge & lh, const Edge & rh) { return lh.cost() == rh.cost(); }
bool operator != (const Edge & lh, const Edge & rh) { return lh.cost() != rh.cost(); }

int main() {
    int n;
    std::cin >> n;
    std::vector<JumpRamp *> ramps{};
    for (int i = 0; i < n; ++i) {
        int x, y, p;
        std::cin >> x >> y >> p;
        ramps.emplace_back(new JumpRamp(x, y, p));
    }
    std::vector<Edge> edges{};
    auto add_edge = [&](const Edge & e) -> void {
        auto end = edges.end();
        auto index = std::lower_bound(edges.begin(), end, e);
        if (edges.size() == 0 || index == end || *index != e) {
            edges.insert(index, e);
        }
    };
    for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j) {
        Edge e1(ramps[i], ramps[j]);
        Edge e2(ramps[j], ramps[i]);
        add_edge(e1);
        add_edge(e2);
    }
}
