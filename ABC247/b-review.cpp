#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::string;
using person_t = std::pair<string, string>;

int main() {
    int n;
    std::cin >> n;
    std::vector<string> names{};
    for (int i = 0; i < n; ++i) {
        string family_name{}, given_name{};
        std::cin >> family_name >> given_name;
        names.push_back(family_name);
        names.push_back(given_name);
    }
    auto is_unique = [&](int person_index) -> bool {
        const string & family_name = names[person_index * 2];
        const string & given_name  = names[person_index * 2 + 1];
        bool fname_unique = true, gname_unique = true;
        for (int i = 0; i < n; ++i) {
            if (i == person_index) continue;
            const string & i_fname = names[i * 2];
            const string & i_gname = names[i * 2 + 1];
            fname_unique = fname_unique && family_name != i_fname && family_name != i_gname;
            gname_unique = gname_unique && given_name != i_fname && given_name != i_gname;
        }
        return fname_unique || gname_unique;
    };
    for (int i = 0; i < n; ++i) {
        if (!is_unique(i)) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}