#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::unordered_map<char, int> mp;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (char c : s) {
            mp[c];
        }
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        ans += mp[c] == k;
    }
    std::cout << ans << std::endl;
}
