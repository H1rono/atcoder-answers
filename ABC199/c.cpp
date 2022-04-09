#include <iostream>
#include <string>
#include <vector>

using vec_chr = std::vector<char>;

struct FLIP_str
{
    int half_len;
    vec_chr *left, *right;

    FLIP_str(int h_len, const std::string &str) : half_len(h_len), left(new vec_chr(h_len, 0)), right(new vec_chr(h_len, 0))
    {
        for (int i = 0; i < half_len; ++i)
        {
            left->at(i) = str[i];
            right->at(i) = str[i + half_len];
        }
    }

    const char &operator[](int i) const
    {
        return i < half_len ? left->at(i) : right->at(i - half_len);
    }

    char &operator[](int i)
    {
        return i < half_len ? left->at(i) : right->at(i - half_len);
    }
};

int main()
{
    int n, q;
    std::string s;
    std::cin >> n >> s >> q;

    FLIP_str flip_str(n, s);
    for (int i = 0; i < q; ++i)
    {
        int t, a, b;
        std::cin >> t >> a >> b;
        a--;
        b--;
        if (t == 1)
        {
            char tmp = flip_str[a];
            flip_str[a] = flip_str[b];
            flip_str[b] = tmp;
        }
        else
        {
            vec_chr *tmp = flip_str.left;
            flip_str.left = flip_str.right;
            flip_str.right = tmp;
        }
    }

    for (char c : *(flip_str.left))
    {
        std::cout << c;
    }
    for (char c : *(flip_str.right))
    {
        std::cout << c;
    }
    std::cout << std::endl;
}

