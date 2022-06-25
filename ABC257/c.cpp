#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>

int main() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::vector<int> weights{};
    std::unordered_map<int, std::pair<int, int>> weight_count{};
    auto add_weight = [&](int weight, bool adult) -> void {
        auto end = weights.end();
        auto index = std::lower_bound(weights.begin(), end, weight);
        if (weights.size() == 0 || index == end || *index != weight) {
            weights.insert(index, weight);
            weight_count[weight] = std::pair<int, int>{0, 0};
        }
        weight_count[weight].first += adult;
        weight_count[weight].second += !adult;
    };
    int adult_count = 0;
    for (int i = 0; i < n; ++i) {
        int weight; std::cin >> weight;
        bool adult = s[i] == '1';
        adult_count += adult;
        add_weight(weight, adult);
    }
    int child_count = 0;
    int ans = adult_count;
    std::pair<int, int> last_state{0, 0};
    for (int weight : weights) {
        auto state = weight_count[weight];
        child_count += state.second;
        adult_count -= state.first;
        ans = std::max(ans, child_count + adult_count);
        last_state = state;
    }
    std::cout << ans << std::endl;
}
