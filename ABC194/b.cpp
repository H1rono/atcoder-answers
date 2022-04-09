#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using pair_ii = std::pair<int, int>;

int calc_time(const pair_ii &wa, const pair_ii &wb)
{
    if (wa.second == wb.second) return wa.first + wb.first;
    return std::max(wa.first, wb.first);
}

int main()
{
    int employee_num;
    std::vector<pair_ii> wa_ts, wb_ts;
    std::cin >> employee_num;
    for (int i = 0; i < employee_num; i++) {
        int wa_t, wb_t;
        std::cin >> wa_t >> wb_t;
        wa_ts.emplace_back(wa_t, i);
        wb_ts.emplace_back(wb_t, i);
    }
    std::sort(wa_ts.begin(), wa_ts.end());
    std::sort(wb_ts.begin(), wb_ts.end());
    pair_ii wa = wa_ts[0], wb = wb_ts[0];
    int ans = calc_time(wa, wb);
    if (wa.second == wb.second) {
        int cand = std::min(
            calc_time(wa, wb_ts[1]),
            calc_time(wa_ts[1], wb)
        );
        ans = std::min(ans, cand);
    }
    std::cout << ans << std::endl;
}