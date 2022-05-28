#include <iostream>
#include <cstdint>

using u64 = std::uint64_t;

u64 gcd(u64 a, u64 b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

u64 lcm(u64 a, u64 b) {
    u64 g = gcd(a, b);
    return a * b / g;
}

u64 floor_sum(u64 n, u64 v) {
    u64 fl = n / v;
    return v * fl * (fl + 1) / 2;
}

int main() {
    u64 n, a, b;
    std::cin >> n >> a >> b;
    u64 ans = (
        floor_sum(n, 1)
        - floor_sum(n, a)
        - floor_sum(n, b)
        + floor_sum(n, lcm(a, b))
    );
    std::cout << ans << std::endl;
}