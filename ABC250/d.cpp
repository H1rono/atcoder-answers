#include <iostream>
#include <vector>
#include <cstdint>

using u64 = std::uint64_t;

std::vector<u64> primes{2, 3, 5};
u64 prime_max = 5;

int  prime_index(u64 x) {
    int ng = -1, ok = primes.size();
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if (primes[mid] < x) {
            ng = mid;
        } else {
            ok = mid;
        }
    }
    return ok;
}

bool isprime_known(u64 x) {
    return primes[prime_index(x)] == x;
}

void register_prime(u64 p) {
    int i = prime_index(p);
    primes.insert(primes.begin() + i, p);
    prime_max = primes.back();
}

bool isprime(u64 x) {
    if (x <= prime_max) {
        return isprime_known(x);
    }
    for (u64 p : primes) {
        if (x % p == 0) {
            return false;
        }
        if (p * p > x) {
            register_prime(x);
            return true;
        }
    }
    for (u64 p = prime_max + 2; p < x; p += 2) {
        if (!isprime(p)) {
            continue;
        }
        if (x % p == 0) {
            return false;
        }
        if (p * p > x) {
            register_prime(x);
            return true;
        }
    }
    return false;
}

int main() {
    u64 n;
    std::cin >> n;
    u64 ans = 0;
    for (u64 q = 2; ; q += 2) {
        if (!isprime(q)) continue;
        u64 q3 = q * q * q;
        if (2 * q3 > n) break;
        for (u64 p = 2; p < q; ++p) {
            if (!isprime(p)) continue;
            u64 k = p * q3;
            if (k > n) break;
            ++ans;
        }
    }
    std::cout << ans << std::endl;
}
