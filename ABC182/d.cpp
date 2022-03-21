#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using ll = long long;
using lpair = std::pair<ll, ll>;

int main() {
    int N;
    std::cin >> N;
    std::vector<lpair> A;
    ll mpos = 0ll, pos = 0ll, a;
    A.push_back(lpair(0ll, 0ll));
    for (int i = 1; i <= N; ++i) {
        std::cin >> a;
        const lpair &p = A.at(i-1);
        lpair np(p.first + a, std::max(p.second, p.first + a));
        A.push_back(np);
        mpos = std::max(mpos, pos + np.second);
        pos += np.first;
    }
    std::cout << mpos << std::endl;
}
