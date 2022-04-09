#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::cout << s[n - 1] << std::endl;
    return 0;
}