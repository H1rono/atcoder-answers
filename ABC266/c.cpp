#include <iostream>

struct Vec2D {
    float x, y;

    Vec2D operator+(const Vec2D& rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Vec2D operator-(const Vec2D& rhs) const {
        return {x - rhs.x, y - rhs.y};
    }

    Vec2D operator*(float rhs) const {
        return {x * rhs, y * rhs};
    }

    Vec2D operator/(float rhs) const {
        return {x / rhs, y / rhs};
    }

    float dot(const Vec2D& rhs) const {
        return x * rhs.x + y * rhs.y;
    }

    float cross(const Vec2D& rhs) const {
        return x * rhs.y - y * rhs.x;
    }
};

bool solve(const Vec2D& a, const Vec2D& b, const Vec2D& c, const Vec2D& d) {
    Vec2D ab = b - a, bc = c - b, cd = d - c, da = a - d;
    return (
        ab.cross(bc) > 0 && bc.cross(cd) > 0 && cd.cross(da) > 0 && da.cross(ab) > 0
    );
}

int main() {
    Vec2D a, b, c, d;
    std::cin
        >> a.x >> a.y
        >> b.x >> b.y
        >> c.x >> c.y
        >> d.x >> d.y;
    std::cout << (solve(a, b, c, d) ? "Yes" : "No") << std::endl;
}
