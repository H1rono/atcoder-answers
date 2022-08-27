#include <iostream>
#include <vector>
#include <cstdint>

using i64 = int64_t;

struct Snuke {
    int time = 0, pos = 0;
    i64 amount = 0;
};

i64 solve(int n, const std::vector<Snuke>& snukes) {
    i64 current_scores[6] = { 0, -1, -1, -1, -1, -1};
    i64 next_scores[6] =    {-1, -1, -1, -1, -1, -1};
    auto snuke_index = [&snukes](int time) -> int {
        int ng = -1, ok = snukes.size();
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (snukes[mid].time < time) {
                ng = mid;
            } else {
                ok = mid;
            }
        }
        return ok;
    };
    for (int t = 1; t <= snukes.back().time; ++t) {
        int i = snuke_index(t);
        for (int pos = 0; pos < 6; ++pos) {
            for (int dpos = -1; dpos <= 1; ++dpos) {
                int npos = pos + dpos;
                if (npos < 0 || npos >= 6) continue;
                i64 score = current_scores[pos];
                if (score < 0) continue;
                if (i < snukes.size() && snukes[i].time == t && snukes[i].pos == npos) {
                    score += snukes[i].amount;
                }
                next_scores[npos] = std::max(next_scores[npos], score);
            }
        }
        for (int pos = 0; pos < 6; ++pos) {
            current_scores[pos] = next_scores[pos];
            next_scores[pos] = -1;
        }
    }
    i64 ans = 0;
    for (int pos = 0; pos < 6; ++pos) {
        ans = std::max(ans, current_scores[pos]);
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Snuke> snukes(n);
    for (auto& snuke : snukes) {
        std::cin >> snuke.time >> snuke.pos >> snuke.amount;
    }
    std::cout << solve(n, snukes) << std::endl;
}
