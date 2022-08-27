#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::cout << s[(n - 1) / 2] << std::endl;
}
