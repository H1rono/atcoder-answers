#include <iostream>
#include <vector>

using std::size_t;

int main() {
    size_t n;
    std::cin >> n;
    std::vector<size_t> a(n, 0);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i]--;
    }
    int ans = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] >= i) {
            continue;
        }
        ans += a[a[i]] == i;
    }
    std::cout << ans << std::endl;
}
