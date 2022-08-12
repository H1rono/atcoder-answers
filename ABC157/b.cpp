#include <iostream>

bool solve (int ** card, int n, int * nums) {
    unsigned int stamps = 0;
    auto get_at = [&stamps](int r, int c) -> bool {
        return stamps >> (r * 3 + c) & 1;
    };
    auto set_at = [&stamps](int r, int c) {
        stamps |= 1 << (r * 3 + c);
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j)
        for (int k = 0; k < 3; ++k) {
            if (card[j][k] == nums[i]) {
                set_at(j, k);
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        // check row
        if (get_at(i, 0) && get_at(i, 1) && get_at(i, 2)) {
            return true;
        }
        // check column
        if (get_at(0, i) && get_at(1, i) && get_at(2, i)) {
            return true;
        }
    }
    // check diagonal
    if (
        get_at(0, 0) && get_at(1, 1) && get_at(2, 2)
        || get_at(0, 2) && get_at(1, 1) && get_at(2, 0)
    ) {
        return true;
    }
    return false;
}

int main() {
    int ** card = new int*[3];
    for (int i = 0; i < 3; i++) {
        card[i] = new int[3];
        for (int j = 0; j < 3; j++) {
            std::cin >> card[i][j];
        }
    }
    int n;
    std::cin >> n;
    int * nums = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    bool ans = solve(card, n, nums);
    std::cout << (ans ? "Yes" : "No") << std::endl;
}
