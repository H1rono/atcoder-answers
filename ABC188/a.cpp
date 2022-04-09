#include <iostream>

int main()
{
    int x, y;
    std::cin >> x >> y;
    int d = x - y;
    bool canChange = -3 < d && d < 3;
    std::cout << (canChange ? "Yes" : "No") << std::endl;
}