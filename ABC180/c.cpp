#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

auto main() -> int {
    long N;
    cin >> N;
    vector<long> res;
    for (long i = 1; i <= sqrt(N); ++i) {
        if (!(N % i)) {
            res.push_back(i);
            long tmp = N / i;
            if (tmp != i) res.push_back(tmp);
        }
    }
    sort(res.begin(), res.end());
    for (const long r : res) {
        cout << r << endl;
    }
}