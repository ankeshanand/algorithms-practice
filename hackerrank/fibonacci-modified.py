a, b, n = map(int, raw_input().split())

dp = [0 for x in xrange(n+1)]
dp[1] = a
dp[2] = b

for i in xrange(3,n+1):
    dp[i] = (dp[i-1] ** 2) + dp[i-2]

print dp[n]
