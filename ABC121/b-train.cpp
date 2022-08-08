#include <iostream>
#include <vector>

int solve(int n, int m, int c, const std::vector<int> & B, const std::vector<std::vector<int>*> & A) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = c;
        for (int j = 0; j < m; j++) {
            sum += A[i]->at(j) * B[j];
        }
        ans += sum > 0;
    }
    return ans;
}

int main() {
    int n, m, c;
    std::cin >> n >> m >> c;
    std::vector<int> B(m, 0);
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }
    std::vector<std::vector<int>*> A(n, nullptr);
    for (int i = 0; i < n; i++) {
        A[i] = new std::vector<int>(m, 0);
        for (int j = 0; j < m; j++) {
            std::cin >> A[i]->at(j);
        }
    }
    std::cout << solve(n, m, c, B, A) << std::endl;
}
