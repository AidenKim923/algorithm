N, K = map(int, input().split())

dp = [[0] * (K + 1) for _ in range(N + 1)]

for i in range(N + 1):
    dp[i][1] = 1

for i in range(N + 1):
    for j in range(2, K + 1):
        for l in range(i + 1):
            dp[i][j] = (dp[i][j] + dp[l][j - 1]) % 1000000000

print(dp[N][K])
