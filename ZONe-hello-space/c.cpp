#include <iostream>
#include <vector>
#include <algorithm>

struct Programmer {
    int power, speed, technique, wisdom, imagination;

    Programmer(int p, int s, int t, int w, int i)
    : power(p), speed(s), technique(t), wisdom(w), imagination(i) {}

    Programmer() : power(0), speed(0), technique(0), wisdom(0), imagination(0) {}
};

int main() {
    int programmer_num;
    std::cin >> programmer_num;
    Programmer cmp_prog;
    for (int i = 0; i < programmer_num; ++i) {
        int p, s, t, w, i_;
        std::cin >> p >> s >> t >> w >> i_;
        Programmer prog = Programmer(p, s, t, w, i_);
        #define update_status(attr_name) cmp_prog.attr_name = std::max(cmp_prog.attr_name, prog.attr_name)
        update_status(power);
        update_status(speed);
        update_status(technique);
        update_status(wisdom);
        update_status(imagination);
        #undef update_status
    }
    std::cout << std::min(
        cmp_prog.power,
        std::min(cmp_prog.speed,
        std::min(cmp_prog.technique,
        std::min(cmp_prog.wisdom,
        cmp_prog.imagination))))
    << std::endl;
}