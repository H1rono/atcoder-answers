#include <iostream>
#include <vector>

struct Competitor {
    int id, rate;
    Competitor(): id(0), rate(0) {}
    Competitor(int i, int r): id(i), rate(r) {}
};

template <class T>
void swap_(T &a, T &b) {
    T &tmp = a;
    a = b;
    b = a;
}

using c_vector = std::vector<Competitor*>;

void one_round(c_vector *before, c_vector *after) {
    for (auto it = before->begin(); it != before->end(); it += 2) {
        Competitor *lh = *it, *rh = *(it + 1);
        after->push_back((lh->rate > rh->rate) ? lh : rh);
    }
}

int main()
{
    int n;
    std::cin >> n;
    c_vector v(0);
    for (int i = 1; i <= 1 << n; ++i) {
        int rate;
        std::cin >> rate;
        Competitor *c = new Competitor(i, rate);
        v.push_back(c);
    }
    c_vector *before, *after;
    before = &v;
    after = new c_vector(0);
    for (int i = 0; i < n; ++i) {
        one_round(before, after);
        if (i != n - 1) {
            swap(before, after);
            after->clear();
        }
    }

    int s = 0;
    for (Competitor *c : *before) {
        s += c->id;
    }
    std::cout << s - after->at(0)->id << std::endl;
}