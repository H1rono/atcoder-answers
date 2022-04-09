#include <iostream>
#include <vector>

using vec_int = std::vector<int>;
using vec_int_ptr = vec_int *;
using vec_vip = std::vector<vec_int_ptr>;

int sorted_vec_index(vec_int * vec, int value) {
    int l = -1, r = vec->size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (value < vec->at(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int dfs(const vec_vip & mapping, int start, vec_int_ptr seen = nullptr) {
    if (seen == nullptr) seen = new vec_int();
    int start_i = sorted_vec_index(seen, start);
    if (start_i != 0 && seen->at(start_i - 1) == start) { return 0; }
    seen->emplace(seen->begin() + start_i, start);
    vec_int_ptr v_ptr = mapping[start];
    int ans = 1;
    for (int i : *v_ptr) {
        ans += dfs(mapping, i, seen);
    }
    return ans;
}

int main() {
    int city_num, road_num, ans = 0;
    std::cin >> city_num >> road_num;
    vec_vip connection(city_num, nullptr);
    for (vec_int_ptr & v : connection) v = new vec_int();
    for (int i = 0; i < road_num; ++i) {
        int city1, city2;
        std::cin >> city1 >> city2;
        vec_int_ptr v = connection[--city1];
        int index = sorted_vec_index(v, --city2);
        v->emplace(v->begin() + index, city2);
    }
    for (int i = 0; i < city_num; ++i) {
        ans += dfs(connection, i);
    }
    std::cout << ans << std::endl;
}

