#include <iostream>
#include <sstream>
#include <vector>

int main() {
    size_t n, q;
    std::cin >> n >> q;
    std::vector<size_t> lens(n, 0);
    std::vector<std::vector<int> *> mat(n, nullptr);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> lens[i];
        std::vector<int> *row = new std::vector<int>(lens[i], 0);
        for (int &a : *row) {
            std::cin >> a;
        }
        mat[i] = row;
    }
    std::ostringstream oss{};
    for (size_t i = 0; i < q; ++i) {
        size_t s, t;
        std::cin >> s >> t;
        std::cout << mat[s - 1]->at(t - 1) << std::endl;
    }
}
