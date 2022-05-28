#include <iostream>
#include <vector>

using vint = std::vector<int>;

int sorted_find(const vint & vec, int x) {
    int ng = -1, ok = vec.size();
    while (ok - ng > 1) {
        int mid = (ok + ng) >> 1;
        if (vec[mid] < x) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    return ok;
}

void sorted_insert(vint & vec, int x) {
    int index = sorted_find(vec, x);
    vec.insert(vec.begin() + index, x);
}

int main() {
    int query_num;
    std::cin >> query_num;
    vint vec{};
    auto query1 = [&]() {
        int x;
        std::cin >> x;
        sorted_insert(vec, x);
    };
    auto query2 = [&]() {
        int x, c;
        std::cin >> x >> c;
        int left = sorted_find(vec, x);
        int right = sorted_find(vec, x + 1);
        int range = std::min(right - left, c);
        auto first = vec.begin() + left;
        auto last = vec.begin() + left + range;
        vec.erase(first, last);
    };
    auto query3 = [&]() {
        int ans = vec.back() - vec.front();
        std::cout << ans << std::endl;
    };
    for (int i = 0; i < query_num; ++i) {
        int query_type;
        std::cin >> query_type;
        switch (query_type)
        {
        case 1: query1(); break;
        case 2: query2(); break;
        case 3: query3(); break;
        default: break;
        }
    }
}
