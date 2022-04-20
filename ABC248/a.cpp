#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    int ans = 45;
    for (char c : s) {
        ans -= c - '0';
    }
    std::cout << ans << std::endl;
}