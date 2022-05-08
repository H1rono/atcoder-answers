#include <iostream>

int main() {
    int h, w, r, c;
    std::cin >> h >> w >> r >> c;
    int ans = (
        (1 < c) // left
        + (c < w) // right
        + (1 < r) // up
        + (r < h) // down
    );
    std::cout << ans << std::endl;
}