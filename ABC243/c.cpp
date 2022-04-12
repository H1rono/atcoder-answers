#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstdint>

using u32 = std::uint32_t;

struct Point {
    u32 x, y;
};

struct Person
{
    int id;
    bool direction_right;
    Point * position;
};

bool operator < (const Person & lh, const Person & rh) {
    return (
        lh.position->x < rh.position->x ? true
        : lh.position->x == rh.position->x ? lh.position->y < rh.position->y
        : false
    );
}

using People = std::vector<Person *>;

int main() {
    int n;
    std::cin >> n;
    std::vector<Point *> points;
    for (int i = 0; i < n; ++i) {
        u32 x, y;
        std::cin >> x >> y;
        Point * p = new Point{x, y};
        points.push_back(p);
    }
    std::string s = "";
    std::cin >> s;
    std::unordered_map<u32, People> people_same_y;
    for (int i = 0; i < n; ++i) {
        Person * person_p = new Person{
            i,
            s[i] == 'R',
            points[i]
        };
        u32 y = points[i]->y;
        if (!people_same_y.count(y)) {
            people_same_y.insert(std::make_pair(y, People{}));
        }
        people_same_y[y].push_back(person_p);
    }
    auto cmp = [](const Person * lh, const Person * rh) {
        return lh->position->x < rh->position->x;
    };
    for (auto & item : people_same_y) {
        People & people = item.second;
        std::sort(people.begin(), people.end(), cmp);
        bool right_person_exists = false;
        for (const Person * person : item.second) {
            right_person_exists = right_person_exists || person->direction_right;
            if (right_person_exists && !person->direction_right) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No" << std::endl;
}