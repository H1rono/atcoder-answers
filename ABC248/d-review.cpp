/*
方針: a_iの値ごとにインデックスを分類し、そのマッピングを用いて各クエリにO(logN)ほどで解答していく
*/

#include <iostream>
#include <vector>
#include <map>

// 二分探索
// ソートされているvector<int>の中から、「x以上で最小の要素」のインデックスを返す
int binary_search(const std::vector<int> & vec, int x) {
    int ng = -1, ok = vec.size();
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if (vec[mid] < x) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    return ok;
}

int main() {
    int n;
    std::cin >> n;
    // a_iごとのiのマッピング
    std::map<int, std::vector<int>> a_tree{};
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        // これだけで勝手にソートされた状態になる、嬉しい
        a_tree[a].push_back(i);
    }
    // クエリ読み込み
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, x;
        std::cin >> l >> r >> x;
        // a_i == x であるiのリスト
        const std::vector<int> & vec = a_tree[x];
        // なんで-1してるのかわかんないけど、合ってるからヨシ！
        int il = binary_search(vec, l - 1);
        int ir = binary_search(vec, r);
        std::cout << (ir - il) << std::endl;
    }
}
