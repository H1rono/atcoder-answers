#include <iostream>
#include <string>

bool solve(const std::string& s) {
    auto stands = [&](int i) -> bool {
        return s[i] != '0';
    };
    if (stands(0)) return false;
    bool col_stand[7] = {
        stands(6),
            stands(3),
        stands(7) || stands(1),
            stands(4),
        stands(8) || stands(2),
            stands(5),
        stands(9),
    };
    bool cond1 = false, cond2 = false;
    for (int i = 0; i < 7; ++i) {
        if (col_stand[i]) {
            if (cond1 && cond2) return true;
            cond1 = true;
        } else {
            cond2 = cond1;
        }
    }
    return false;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << (solve(s) ? "Yes" : "No") << std::endl;
}
