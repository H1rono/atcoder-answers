#include <iostream>
#include <string>
#include <vector>

int main() {
    size_t h, w;
    std::cin >> h >> w;
    std::vector<std::string> grid(h);
    for (size_t i = 0; i < h; ++i) {
        std::cin >> grid[i];
    }
    std::vector<bool> include_row(h, false), include_col(w, false);
    for (size_t r = 0; r < h; ++r)
    for (size_t c = 0; c < w; ++c) {
        if (grid[r][c] == '#') {
            include_row[r] = true;
            include_col[c] = true;
        }
    }
    for (size_t r = 0; r < h; ++r) if (include_row[r]) {
        for (size_t c = 0; c < w; ++c) if (include_col[c]) {
            std::cout << grid[r][c];
        }
        std::cout << std::endl;
    }
}
