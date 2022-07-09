#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double a, b, degree;
    std::cin >> a >> b >> degree;
    double radian = degree * std::acos(-1) / 180.0;
    double x = a * std::cos(radian) - b * std::sin(radian);
    double y = a * std::sin(radian) + b * std::cos(radian);
    std::cout << std::fixed << std::setprecision(18);
    std::cout << x << ' ' << y << std::endl;
}