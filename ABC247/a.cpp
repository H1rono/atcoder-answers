#include <iostream>
#include <string>

int main() {
    std::string s = "";
    std::cin >> s;
    std::cout << '0';
    for (int i = 0; i < 3; ++i) {
        std::cout << s[i];
    }
    std::cout << std::endl;
}
