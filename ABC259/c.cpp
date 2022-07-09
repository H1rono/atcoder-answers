#include <iostream>
#include <string>
#include <vector>

using vec_str = std::vector<std::string>;

vec_str * separate(const std::string & str) {
    vec_str * result = new vec_str{};
    using string_iter = std::string::const_iterator;
    string_iter last_i = str.begin();
    for (string_iter it = str.begin(); it != str.end(); ++it) {
        if (*last_i != *it) {
            result->emplace_back(last_i, it);
            last_i = it;
        }
    }
    result->emplace_back(last_i, str.end());
    return result;
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    vec_str * s_separated = separate(s);
    vec_str * t_separated = separate(t);
    bool result = true;
    int len = s_separated->size();

    if (len != t_separated->size()) {
        result = false;
        goto ANSWER;
    }

    for (int i = 0; i < len; ++i) {
        const std::string & s_str = s_separated->at(i);
        const std::string & t_str = t_separated->at(i);
        int s_str_len = s_str.size();
        int t_str_len = t_str.size();
        char s_chr = s_str[0];
        char t_chr = t_str[0];
        if (
            s_chr != t_chr
            || s_str_len > t_str_len
            || (s_str_len == 1 && s_str_len < t_str_len)
        ) {
            result = false;
            goto ANSWER;
        }
    }

    result = true;

    ANSWER:
    std::cout << (result ? "Yes" : "No") << std:: endl;
}