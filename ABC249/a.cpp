#include <iostream>
#include <algorithm>

int main() {
    int a, b, c, d, e, f, x;
    std::cin >> a >> b >> c >> d >> e >> f >> x;
    auto walk = [&x](int walk_span, int walk_speed, int rest_span) -> int {
        int walk_length = 0, time = x;
        while (time > 0) {
            if (walk_span > time) {
                walk_length += walk_speed * time;
                time = 0;
                continue;
            } else {
                walk_length += walk_speed * walk_span;
                time -= walk_span;
            }
            time = std::max(0, time - rest_span);
        }
        return walk_length;
    };
    int takahasi_walk = walk(a, b, c);
    int aoki_walk = walk(d, e, f);
    std::cout << (
        takahasi_walk > aoki_walk ? "Takahashi"
        : takahasi_walk < aoki_walk ? "Aoki" : "Draw"
    ) << std::endl;
}