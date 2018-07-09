def comb(n, k):
    global memo
    if k == 0 or n == k:
        return 1
    if memo[n - 1][k - 1] == -1:
        memo[n - 1][k - 1] = comb(n - 1, k - 1)
    if memo[n - 1][k] == -1:
        memo[n - 1][k] = comb(n - 1, k)
    return memo[n - 1][k - 1] + memo[n - 1][k]


if __name__ == '__main__':
    N, M = [int(x) for x in input().split(' ')]
    memo = [[-1] * 105 for x in range(105)]
    print(comb(N, M))

