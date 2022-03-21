#include <iostream>
//#include <vector>
#include <string>

using namespace std;
//using L = long long;

int main() {
    int N;
    cin >> N;
    string ans;
    if (N % 2 != 0) {
        ans = "Black";
    } else {
        ans = "White";
    }
    cout << ans << endl;
}