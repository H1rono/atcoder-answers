#include <iostream>
#include <vector>

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> rates(n, 0);
    for (int &a : rates) std::cin >> a;
    // 灰、茶、緑、水、青、黄、橙、赤、自由
    // ~400, ~800, ~1200, ~1600, ~2000, ~2400, ~2800, ~3200, ~
    std::vector<int> colors(9, 0);
    for (int a : rates) {
        if (a < 400) {
            ++colors[0];
        } else if (a < 800) {
            ++colors[1];
        } else if (a < 1200) {
            ++colors[2];
        } else if (a < 1600) {
            ++colors[3];
        } else if (a < 2000) {
            ++colors[4];
        } else if (a < 2400) {
            ++colors[5];
        } else if (a < 2800) {
            ++colors[6];
        } else if (a < 3200) {
            ++colors[7];
        } else {
            ++colors[8];
        }
    }
    int min_colors = 0;
    for (size_t i = 0; i < 8; ++i) {
        min_colors += colors[i] > 0;
    }
    int max_colors = min_colors + colors[8];
    if (min_colors == 0) min_colors = max_colors > 0;
    std::cout << min_colors << " " << max_colors << std::endl;
}
