#include <cstdint>
#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<bool> *>;

Matrix rotate_mat(const Matrix &mat) {
    std::size_t n = mat.size();
    Matrix ret(n, nullptr);
    for (std::size_t r = 0; r < n; ++r) {
        std::vector<bool> *row = new std::vector<bool>(n, false);
        for (std::size_t c = 0; c < n; ++c) {
            row->at(c) = mat.at(n - c - 1)->at(r);
        }
        ret[r] = row;
    }
    return ret;
}

void destruct_mat(Matrix &mat) {
    for (auto i = mat.begin(); i != mat.end(); ++i) {
        delete *i;
        *i = nullptr;
    }
}

int main() {
    std::size_t n;
    std::cin >> n;
    std::vector<std::vector<bool> *> a(n, nullptr), b(n, nullptr);
    // read a
    for (std::size_t r = 0; r < n; ++r) {
        std::vector<bool> *row = new std::vector<bool>(n, false);
        for (std::size_t c = 0; c < n; ++c) {
            int v;
            std::cin >> v;
            row->at(c) = v == 1;
        }
        a[r] = row;
    }
    // read b
    for (std::size_t r = 0; r < n; ++r) {
        std::vector<bool> *row = new std::vector<bool>(n, false);
        for (std::size_t c = 0; c < n; ++c) {
            int v;
            std::cin >> v;
            row->at(c) = v == 1;
        }
        b[r] = row;
    }
    // check
    for (int i = 0; i < 4; ++i) {
        bool ok = true;
        for (std::size_t r = 0; r < n; ++r) {
            for (std::size_t c = 0; c < n; ++c) {
                if (a[r]->at(c)) {
                    ok = b[r]->at(c);
                    if (!ok) {
                        break;
                    }
                }
            }
            if (!ok) {
                break;
            }
        }
        if (ok) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        Matrix tmp = rotate_mat(a);
        destruct_mat(a);
        a = tmp;
    }
    std::cout << "No" << std::endl;
}
