#include <iostream>
#include <vector>

using vint = std::vector<int>;
using vvint = std::vector<vint>;

void print_vint(const vint & v) {
    std::cout << v.front();
    for (int i = 1; i < v.size(); ++i) {
        std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

void print_vvint(const vvint & v) {
    for (int i = 0; i < v.size(); ++i) {
        print_vint(v[i]);
    }
    std::cout << std::endl;
}

bool operator==(const vint & lh, const vint & rh) {
    if (lh.size() != rh.size()) return false;
    // std::cout << "vint_eq" << std::endl;
    // print_vint(lh);
    // print_vint(rh);
    for (int i = 0; i < lh.size(); ++i) {
        if (lh[i] != rh[i]) return false;
    }
    return true;
}

bool solve(const vvint & a, const vvint & b) {
    int h1 = a.size(), w1 = a[0].size(), h2 = b.size(), w2 = b[0].size();
    if (w1 == w2) {
        // std::cout << "w1 == w2" << std::endl;
        int last_r1 = 0;
        for (int r2 = 0; r2 < h2; ++r2) {
            bool ok = false;
            // std::cout << "r2 = " << r2 << ", r1 = ";
            for (int r1 = last_r1; r1 < h1; ++r1) {
                // std::cout << r1;
                ok = a[r1] == b[r2];
                if (ok) {
                    last_r1 = r1;
                    break;
                }
                // std::cout << ", ";
            }
            // std::cout << std::endl;
            if (!ok) return false;
        }
        return true;
    }
    // print_vvint(a);
    for (int i = 0; i < w1; ++i) {
        vvint c(h1, vint(w1 - 1));
        for (int j = 0; j < w1; ++j) {
            if (j == i) continue;
            for (int k = 0; k < h1; ++k) {
                c[k][j - (j > i)] = a[k][j];
            }
        }
        if (solve(c, b)) {
            return true;
        }
    }

    return false;
}

int main() {
    int h1, w1;
    std::cin >> h1 >> w1;
    vvint a(h1, vint(w1, 0));
    for (int i = 0; i < h1; i++) {
        for (int j = 0; j < w1; j++) {
            std::cin >> a[i][j];
        }
    }
    int h2, w2;
    std::cin >> h2 >> w2;
    vvint b(h2, vint(w2, 0));
    for (int i = 0; i < h2; i++) {
        for (int j = 0; j < w2; j++) {
            std::cin >> b[i][j];
        }
    }
    std::cout << (solve(a, b) ? "Yes" : "No") << std::endl;
}
