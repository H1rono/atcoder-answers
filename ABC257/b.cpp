#include <iostream>
#include <vector>

int main() {
    int n, k, q;
    std::cin >> n >> k >> q;
    std::vector<int> positions(k, 0);
    for (int & a : positions) std::cin >> a;
    for (int i = 0; i < q; ++i) {
        int l;
        std::cin >> l;
        int & a = positions[l - 1];
        if (a == n || (l != k && positions[l] == a + 1)) {
            continue;
        } else {
            a++;
        }
    }
    for (int i = 0; i < k; ++i) {
        std::cout << (i ? " " : "") << positions[i];
    }
    std::cout << std::endl;
}
