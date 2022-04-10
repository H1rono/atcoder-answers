#include <iostream>
#include <string>
#include <unordered_map>

using std::string;

int main() {
    int n;
    std::cin >> n;
    std::unordered_map<int, string> note{};
    for (int i = 1; i <= n; ++i) {
        note[i] = i == 1 ? " 1 " : note[i - 1] + std::to_string(i) + note[i - 1];
    }
    std::cout << note[n] << std::endl;
}