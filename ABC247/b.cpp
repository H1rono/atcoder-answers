#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::string;

struct Person {
    string family_name, given_name;
};

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<Person> * persons = new std::vector<Person>();
    std::map<string, int> * name_counts = new std::map<string, int>();
    for (int i = 0; i < n; ++i) {
        string family{}, given{};
        std::cin >> family >> given;
        persons->push_back(Person{family, given});
        (*name_counts)[family] += 1;
        (*name_counts)[given] += 1;
    }
    for (const Person & person : *persons) {
        bool family_name_ok = (*name_counts)[person.family_name] == 1;
        bool given_name_ok  = (*name_counts)[person.given_name ] == 1;
        if (!(family_name_ok || given_name_ok)) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}
