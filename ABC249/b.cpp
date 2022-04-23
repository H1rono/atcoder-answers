#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string s;
    std::cin >> s;
    bool contain_large = false, contain_small = false, all_chars_different = true;
    std::unordered_set<char> chars;
    for (char c : s) {
        contain_large = contain_large || ('A' <= c && c <= 'Z');
        contain_small = contain_small || ('a' <= c && c <= 'z');
        all_chars_different = chars.count(c) == 0;
        chars.insert(c);
        if (!all_chars_different) break;
    }
    bool is_good = contain_large && contain_small && all_chars_different;
    std::cout << (is_good ? "Yes" : "No") << std::endl;
}
