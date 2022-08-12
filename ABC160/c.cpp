#include <iostream>
#include <vector>
#include <algorithm>

int solve(int k, int n, const std::vector<int> &a) {
    std::vector<int> a_(a.begin(), a.end());
    std::sort(a_.begin(), a_.end());
    int dist_max = 0;
    for (int i = 0; i + 1 < n; ++i) {
        int dist = a_[i + 1] - a_[i];
        dist_max = std::max(dist_max, dist);
    }
    dist_max = std::max(dist_max, k - a_[n - 1] + a_[0]);
    return k - dist_max;
}

int main() {
    int k, n;
    std::cin >> k >> n;
    std::vector<int> a(n);
    for (int & ai : a) {
        std::cin >> ai;
    }
    std::cout << solve(k, n, a) << std::endl;
}
