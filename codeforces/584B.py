MOD = 1000000007

n = int(raw_input())
result1, result2 = 1, 1
for i in range(1, 3*n + 1):
    result1 = (result1 * 3) % MOD

for i in range(1, n + 1):
    result2 = (result2 * 7) % MOD

result = (result1 - result2) % MOD
print result
