#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using i64 = std::int64_t;

int main() {
    size_t h, w, n;
    i64 r, c;
    std::cin >> h >> w >> r >> c >> n;
    std::vector<i64> walls_rc(n, 0), walls_cr(n, 0);
    for(size_t i = 0; i < n; ++i) {
        i64 r, c;
        std::cin >> r >> c;
        r--;
        c--;
        walls_rc[i] = r + c * h;
        walls_cr[i] = c + r * w;
    }
    std::sort(walls_rc.begin(), walls_rc.end());
    std::sort(walls_cr.begin(), walls_cr.end());
    r--;
    c--;
    size_t q;
    std::cin >> q;
    for(size_t _ = 0; _ < q; ++_) {
        char d;
        i64 l;
        std::cin >> d >> l;
        if(d == 'U') {
            auto i =
                std::lower_bound(walls_rc.begin(), walls_rc.end(), r + c * h);
            i64 border = 0;
            if(i == walls_rc.begin() || *(i - 1) / h != c) {
                border = 0;
            } else {
                border = (*(i - 1) % h) + 1;
            }
            r = std::max(std::max(static_cast<i64>(0), r - l), border);
        } else if(d == 'D') {
            auto i =
                std::lower_bound(walls_rc.begin(), walls_rc.end(), r + c * h);
            i64 border = 0;
            if(i == walls_rc.end() || *i / h != c) {
                border = h;
            } else {
                border = *i % h;
            }
            r = std::min(std::min(static_cast<i64>(h - 1), r + l), border - 1);
        } else if(d == 'L') {
            auto i =
                std::lower_bound(walls_cr.begin(), walls_cr.end(), c + r * w);
            i64 border = 0;
            if(i == walls_cr.begin() || *(i - 1) / w != r) {
                border = 0;
            } else {
                border = (*(i - 1) % w) + 1;
            }
            c = std::max(std::max(static_cast<i64>(0), c - l), border);
        } else if(d == 'R') {
            auto i =
                std::lower_bound(walls_cr.begin(), walls_cr.end(), c + r * w);
            i64 border = 0;
            if(i == walls_cr.end() || *i / w != r) {
                border = w;
            } else {
                border = *i % w;
            }
            c = std::min(std::min(static_cast<i64>(w - 1), c + l), border - 1);
        } else {
            abort();
        }
        std::cout << (r + 1) << " " << (c + 1) << std::endl;
    }
}
