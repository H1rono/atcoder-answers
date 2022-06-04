def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    maybe_sorted = [
        sorted(
            A[j] for j in range(i, n, k)
        ) for i in range(k)
    ]
    last_a = 0
    for i in range(n):
        col, row = divmod(i, k)
        a = maybe_sorted[row][col]
        if a < last_a:
            print("No")
            return
        last_a = a
    print("Yes")

main()