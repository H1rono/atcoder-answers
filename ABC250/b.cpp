#include <iostream>
#include <vector>

using vecbool = std::vector<bool>;

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) { // タイルの行
        for (int r = 0; r < a; ++r) { // マスの行
            for (int j = 0; j < n; ++j) { // タイルの列
                for (int c = 0; c < b; ++c) { // マスの列
                    bool isblack = (i + j) & 1;
                    std::cout << (isblack ? '#' : '.');
                }
            }
            std::cout << std::endl;
        }
    }
}