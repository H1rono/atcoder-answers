#include <cstdint>
#include <iostream>
#include <string>

int main() {
    std::size_t n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int ok = 0, ng = 0;
    for (auto c : s) {
        if (c == 'o') {
            ok++;
        } else if (c == 'x') {
            ng++;
        }
    }
    bool ans = ok > 0 && ng == 0;
    std::cout << (ans ? "Yes" : "No") << std::endl;
}
