#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

int solve(const std::string & s) {
    // m[s] := swapの繰り返しでsが最初に現れる回数
    std::unordered_map<std::string, int> m{};
    const std::string desire = "atcoder";
    m[s] = 0;
    std::vector<std::string> nexts{s};
    for (int i = 0; i < nexts.size(); ++i) {
        std::string t = nexts[i];
        for (int j = 0; j < t.size() - 1; ++j) {
            std::string next = t;
            std::swap(next[j], next[j + 1]);
            if (m.count(next)) continue;
            m[next] = m[t] + 1;
            if (next == desire) return m[next];
            nexts.push_back(next);
        }
    }
    return m[desire];
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << solve(s) << std::endl;
    return 0;
}