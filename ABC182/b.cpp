#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N, 0), gcd(1024, 0);
    for (int &a : A) {
        cin >> a;
        for (int i = 2; i <= a; ++i) {
            gcd[i] += (a % i == 0);
        }
    }
    int m_ind = 0, m_num = 0;
    for (int i = 2; i <= 1000; ++i) {
        int g = gcd[i];
        if (m_num <= g) {
            m_ind = i;
            m_num = g;
        }
        if (m_num == N) {
            break;
        }
    }
    cout << m_ind << endl;
}