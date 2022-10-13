#include <iostream>
#include <vector>

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> a(n, 0);
    int a_max = 0;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
        a_max = std::max(a_max, a[i]);
    }
    const int offset = 1;
    std::vector<int> sample(a_max + 10, 0);
    for (size_t i = 0; i < n; ++i) {
        int v = a[i] + offset;
        ++sample[v - 1];
        ++sample[v];
        ++sample[v + 1];
    }
    int ans = 0;
    for (size_t i = 0; i < a_max + 10; ++i) {
        if (sample[ans] < sample[i]) {
            ans = i;
        }
    }
    std::cout << sample[ans] << std::endl;
}
