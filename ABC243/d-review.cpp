/**
 * LまたはRの後ろにUがある場合、この2回の移動で元の頂点に戻る
 * => 文字列から削除して問題なし
 * 削除する文字はstackなどを用いてO(N)で調べる
 * 削除後の文字列は[0個以上のU][0個以上のLまたはR]の形式であるため、単調減少してから単調増加
 * => 移動途中で値が表現可能な範囲を超えることはない
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

using u64 = std::uint64_t;

int main() {
    u64 n, x;
    std::cin >> n >> x;
    std::string s;
    std::cin >> s;
    std::vector<char> processed_s{};
    for (char c : s) {
        if (c == 'U') {
            if (!processed_s.size() || processed_s.back() == 'U') {
                // 後ろから要素を追加することで、元の順番を保つ
                processed_s.push_back(c);
            } else {
                // processed_s.back()がLまたはRで、今Uを末尾に追加しようとしている => 移動で元に戻るため、削除
                processed_s.pop_back();
            }
        } else {
            processed_s.push_back(c);
        }
    }
    for (char c : processed_s) {
        switch (c)
        {
        case 'U':
            x = x >> 1;
            break;
        case 'L':
            x = x << 1;
            break;
        case 'R':
            x = (x << 1) + 1;
            break;
        default:
            break;
        }
    }
    std::cout << x << std::endl;
}
