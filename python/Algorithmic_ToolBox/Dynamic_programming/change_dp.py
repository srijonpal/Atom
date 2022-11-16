def get_change(m):
    changes = [1, 3, 4]
    dp = [1000000]*(m+1)
    dp[0] = 0
    for i in range(len(changes)):
        for j in range(1, m+1):
            if changes[i] > j:
                dp[j] = dp[j]
            else:
                dp[j] = min(dp[j], dp[j - changes[i]]+1)
    return dp[m]


if __name__ == '__main__':
    m = int(input())
    print(get_change(m))
