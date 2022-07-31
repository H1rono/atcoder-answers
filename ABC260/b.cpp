#include <iostream>
#include <vector>

using vint = std::vector<int>;

struct score_info {
    int score, id;
};

bool operator < (const score_info & lh, const score_info & rh) {
    return (
        lh.score < rh.score
        || (lh.score == rh.score && lh.id > rh.id)
    );
}

using vec_score = std::vector<score_info>;

int index_of(const vec_score & vec, score_info s) {
    int ng = -1, ok = vec.size();
    while (ok - ng > 1) {
        int mid = (ok + ng) >> 1;
        if (vec[mid] < s) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    return ok;
}

void insert_score(vec_score * vec, score_info s) {
    int i = index_of(*vec, s);
    vec->insert(vec->begin() + i, s);
}

int main() {
    int n, x, y, z;
    std::cin >> n >> x >> y >> z;

    vint math_scores{};
    vec_score math_score_info{};
    for (int i = 0; i < n; ++i) {
        int score;
        std::cin >> score;
        math_scores.push_back(score);
        insert_score(&math_score_info, score_info{score, i});
    }

    vint eng_scores{};
    vec_score eng_score_info{};
    vec_score sum_score_info{};
    for (int i = 0; i < n; ++i) {
        int eng_score;
        std::cin >> eng_score;
        eng_scores.push_back(eng_score);
        insert_score(&eng_score_info, {eng_score, i});
        int math_score = math_scores[i];
        int sum_score = eng_score + math_score;
        insert_score(&sum_score_info, {math_score + eng_score, i});
    }

    std::vector<bool> pass(n, false);
    int math_passed = 0;
    for (int i = n - 1; i >= 0 && math_passed < x; --i) {
        score_info s = math_score_info[i];
        if (pass[s.id]) continue;
        pass[s.id] = true;
        math_passed++;
        if (math_passed == x) break;
    }

    int eng_passed = 0;
    for (int i = n - 1; i >= 0 && eng_passed < y; --i) {
        score_info s = eng_score_info[i];
        if (pass[s.id]) continue;
        pass[s.id] = true;
        eng_passed++;
        if (eng_passed == y) break;
    }

    int sum_passed = 0;
    for (int i = n - 1; i >= 0 && sum_passed < z; --i) {
        score_info s = sum_score_info[i];
        if (pass[s.id]) continue;
        pass[s.id] = true;
        sum_passed++;
        if (sum_passed == z) break;
    }

    for (int i = 0; i < n; ++i) {
        if (!pass[i]) continue;
        std::cout << (i + 1) << std::endl;
    }
}