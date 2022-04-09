#include <iostream>
#include <string>
#include <utility>

class Pos2D {
public:
    int x, y;

    Pos2D & operator+=(const Pos2D & other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    void rotate_right() {
        int x_ = x, y_ = y;
        x = y_;
        y = -x_;
    }
};

Pos2D operator+(const Pos2D & left, const Pos2D & right) {
    return Pos2D{left.x + right.x, left.y + right.y};
}

int main() {
    int len;
    std::string moving_info;
    std::cin >> len >> moving_info;
    Pos2D position{0, 0}, dif_pos{1, 0};
    for (char c : moving_info) {
        if (c == 'S') {
            position += dif_pos;
        } else if (c == 'R') {
            dif_pos.rotate_right();
        }
    }
    std::cout << position.x << " " << position.y << std::endl;
    return 0;
}

