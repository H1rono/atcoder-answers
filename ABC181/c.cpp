#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
using L = long long;

int main() {
    int N;
    double x, y, dx, dy, t;
    bool inf = false;
    vector<pair<double, double>> points;
    set<double> tans;
    cin >> N;
    string ans = "No";
    cin >> x >> y;
    points.push_back(pair(x, y));
    for (int i = 1; i < N; ++i) {
        cin >> x >> y;
        for (auto p : points) {
            dx = p.first - x;
            dy = p.second - y;
            if (dx == 0) {
                if (inf) {
                    ans = "Yes";
                    goto END;
                }
                inf = true;
            } else {
                t = dy / dx;
                if (tans.count(t) != 0) {
                    ans = "Yes";
                    goto END;
                }
                tans.insert(t);
            }
        }
        points.push_back(pair<double, double>(x, y));
        tans.clear();
        inf = false;
    }
    END:
    cout << ans << endl;
}