n, m = map(int, raw_input().split())

coins =  [int(x) for x in raw_input().split()]

dp = [[0 for i in xrange(m+1)] for c in xrange(n+1)]

for i in xrange(m+1):
    dp[0][i] = 1

for c in xrange(1,n+1):
    for i in xrange(1,m+1):
        dp[c][i] += dp[c][i-1]
        if coins[i-1] <= c:
            dp[c][i] += dp[c-coins[i-1]][i]

print dp[n][m]
