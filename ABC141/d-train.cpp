//#include <algorithm>
//#include <vector>
#include <queue>
//#include <set>
#include <iostream>

using namespace std;
using L = long long;

auto main() -> int {
    L N, M, ans = 0;
    cin >> N >> M;
    priority_queue<L> A;
    for (int i = 0; i < N; ++i) {
        L a;
        cin >> a;
        A.push(a);
    }
    for (int _ = 0; _ < M; ++_) {
        L tmp = A.top() >> 1;
        A.pop();
        A.push(tmp);
    }
    for (int i = 0; i < N; ++i) {
        ans += A.top();
        A.pop();
    }
    cout << ans << endl;
}