primes = [2, 3, 5]
prime_max = 5


def prime_index(x):
    ng, ok = -1, len(primes)
    while ok - ng > 1:
        i = (ok + ng) // 2
        m = primes[i]
        if m < x:
            ng = i
        else:
            ok = i
    return ok


def isprime_known(x):
    i = prime_index(x)
    return primes[i] == x


def register_prime(p):
    global prime_max
    i = prime_index(p)
    primes.insert(i, p)
    prime_max = primes[-1]


def isprime(x):
    if x <= prime_max:
        return isprime_known(x)
    for p in primes:
        if not x % p:
            return False
        if p * p > x:
            register_prime(x)
            return True
    for p in range(prime_max + 2, x, 2):
        if not isprime(p):
            continue
        if not x % p:
            return False
        if p * p > x:
            register_prime(x)
            return True


if __name__ == "__main__":
    n = int(input())
    ans = 0
    for q, _ in enumerate(iter(object, None), 2):
        if not isprime(q):
            continue
        q3 = pow(q, 3)
        if 2 * q3 > n:
            break
        for p in range(2, q):
            if not isprime(p):
                continue
            k = p * q3
            if k > n:
                break
            ans += 1
    print(ans)

