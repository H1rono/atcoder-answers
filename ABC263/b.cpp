#include <iostream>
#include <vector>

int solve(const std::vector<int> & p) {
    int ans = 0;
    int i = p.size() - 1;
    while (i > 0) {
        i = p[i] - 1;
        ans++;
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        std::cin >> p[i];
    }
    std::cout << solve(p) << std::endl;
}