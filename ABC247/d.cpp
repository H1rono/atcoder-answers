#include <iostream>
#include <stdint.h>
#include <deque>
#include <utility>

using i64 = std::int64_t;
using i64s = std::pair<i64, i64>;
using cylinder_t = std::deque<i64s *>;

void push_cylinder(cylinder_t * cylinder, i64 x, i64 c) {
    cylinder->push_back(new i64s{x, c});
}

i64 pop_cylinder(cylinder_t * cylinder, const i64 num) {
    i64s * p = cylinder->front();
    i64 rest_num = num - p->second;
    if (rest_num < 0) {
        p->second = -rest_num;
        return p->first * num;
    } else if (rest_num == 0) {
        i64 sum = p->first * p->second;
        cylinder->pop_front();
        return sum;
    } else {
        i64 sum_ = p->first * p->second;
        cylinder->pop_front();
        return sum_ + pop_cylinder(cylinder, rest_num);
    }
}

int main() {
    int n;
    std::cin >> n;
    cylinder_t * cylinder = new cylinder_t();
    for (int i = 0; i < n; ++i) {
        int query_type;
        std::cin >> query_type;
        if (query_type == 1) {
            int x, c;
            std::cin >> x >> c;
            push_cylinder(cylinder, x, c);
        } else {
            int c;
            std::cin >> c;
            std::cout << pop_cylinder(cylinder, c) << std::endl;
        }
    }
}
