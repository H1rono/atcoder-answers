#include <iostream>
#include <vector>

int main() {
    size_t h, w, r, c, n;
    std::cin >> h >> w >> r >> c >> n;
    std::vector<std::vector<bool>> iswall(h, std::vector<bool>(w, false));
    for(size_t i = 0; i < n; ++i) {
        size_t r, c;
        std::cin >> r >> c;
        iswall[r - 1][c - 1] = true;
    }
    size_t q;
    std::cin >> q;
    for(size_t _ = 0; _ < q; ++_) {
        char d;
        size_t l;
        std::cin >> d >> l;
        int dr = 0, dc = 0;
        switch(d) {
        case 'U':
            dr = -1;
            break;
        case 'D':
            dr = 1;
            break;
        case 'L':
            dc = -1;
            break;
        case 'R':
            dc = 1;
            break;
        }
        for(size_t i = 0; i < l; ++i) {
            r += dr;
            c += dc;
            if((r <= 0 || r > h) || (c <= 0 || c > w) || iswall[r - 1][c - 1]) {
                r -= dr;
                c -= dc;
                break;
            }
        }
        std::cout << r << " " << c << std::endl;
    }
}
