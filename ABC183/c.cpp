#include <iostream>
#include <vector>

using ivec = std::vector<int>;
using ivvec = std::vector<ivec>;

ivec search(const ivvec &time, const int gone, int pos) {
    ivec ans{};
    int l = time.size();
    for (int i = 0; i < l; ++i) {
        if (gone & 1<<i) { continue; }
        int t = time[pos][i];
        ivec v = search(time, gone | 1<<i, i);
        for (auto a : v) {
            ans.push_back(t + a);
        }
    }
    if (ans.size() == 0) {
        ans.push_back(time[pos][0]);
    }
    return ans;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    ivvec T(N, ivec());
    for (ivec &v : T) {
        for (int i = 0; i < N; ++i) {
            int t;
            std::cin >> t;
            v.push_back(t);
        }
    }
    ivec res = search(T, 1, 0);
    int ans = 0;
    for (int a : res) {
        ans += a == K;
    }
    std::cout << ans << std::endl;
}