def optimal_sequence(n):
    dp = []
    for i in range(3):
        dp.append([0]*(n+1))
    for i in range(2, n+1):
        dp[0][i] = dp[0][i-1]+1
    for i in range(2, 4):
        for j in range(1, n+1):
            if j % i == 0:
                dp[i-1][j] = min(dp[i-2][j], dp[i-1][j//i]+1)
            else:
                dp[i-1][j] = dp[i-2][j]
    print(dp)


n = int(input())
optimal_sequence(n)
