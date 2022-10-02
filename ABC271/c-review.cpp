#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n, 0);
    for (int &v : a) {
        std::cin >> v;
    }
    std::vector<bool> has_volume(n + 2, false);
    int sold_count = 0;
    for (int v : a) {
        if (v <= n && !has_volume[v]) {
            has_volume[v] = true;
            continue;
        }
        sold_count += 1;
    }
    int left = 1, right = n + 1;
    while (1) {
        while (has_volume[left]) left += 1;
        while (right > 0 && !has_volume[right]) right -= 1;
        if (sold_count >= 2) {
            sold_count -= 2;
            has_volume[left] = true;
        } else {
            if (right <= left)  break;
            has_volume[right] = false;
            sold_count += 1;
        }
    }
    std::cout << (left - 1) << std::endl;
}
