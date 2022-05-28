#include <iostream>
#include <vector>
#include <string>

int main() {
    int w;
    std::cin >> w;
    int w_3 = w / 3;
    std::vector<int> as{};
    std::vector<bool> g(w_3 + 10, false);
    for (int a = 1; a <= w_3; ++a) {
        if (g[a]) continue;
        g[a] = true;
        for (int b : as) {
            int v = a + b;
            if (v > w_3) break;
            g[v] = true;
        }
        as.push_back(a);
    }
    std::cout
        << (as.size() + 2) << std::endl
        << "1 2";
    for (int a : as) {
        std::cout << " " << (a * 3);
    }
    std::cout << std::endl;
}
