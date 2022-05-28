#include <iostream>
#include <algorithm>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int l[] = {a, b, c};
    std::sort(std::begin(l), std::end(l));
    std::cout << (l[1] == b ? "Yes" : "No") << std::endl;
}