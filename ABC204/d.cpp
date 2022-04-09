#include <iostream>
#include <vector>

using vec_int = std::vector<int>;
using vint_iter = vec_int::iterator;

int sorted_vec_index(const vec_int & vec, int value) {
    int l = -1, r = vec.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (value < vec[mid]) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

bool can_finish(const vint_iter & begin, const vint_iter & end, int limit, int ignore = 0) {
    auto next = begin + 1;
    if (limit < ignore) { return false; }
    if (begin == end) { return true; }
    int t = *begin;
    bool a = can_finish(next, end, limit - t, ignore);
    bool b = can_finish(next, end, limit, ignore + t);
    return a | b;
}

int main() {
    int dish_num, time_sum = 0;
    std::cin >> dish_num;
    vec_int times;
    for (int i = 0; i < dish_num; ++i) {
        int oven_time;
        std::cin >> oven_time;
        time_sum += oven_time;
        int index = sorted_vec_index(times, oven_time);
        times.emplace(times.begin() + index, oven_time);
    }
    int l_time = 0, r_time = time_sum;
    auto t_begin = times.begin(), t_end = times.end();
    while (r_time - l_time > 1) {
        int mid = (l_time + r_time) / 2;
        bool res = can_finish(t_begin, t_end, mid, time_sum - mid);
        std::cout << mid;
        if (res) {
            r_time = mid;
            std::cout << " OK\n";
        } else {
            l_time = mid;
            std::cout << " NG\n";
        }
    }
    std::cout << r_time << std::endl;
}

