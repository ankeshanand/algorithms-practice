n = int(raw_input())
a1 = [int(x) for x in raw_input().split()]
a2 = [int(x) for x in raw_input().split()]

b = [int(x) for x in raw_input().split()]

cumm_sum1, cumm_sum2 = [0], [0]

sum = 0
for i in a1:
    sum += i
    cumm_sum1.append(sum)

sum = 0
for i in reversed(a2):
    sum += i
    cumm_sum2.append(sum)

min1 = float('inf')
min2 = float('inf')

cost = 0
for i in xrange(n):
    cost = 0
    cost += b[n-1-i]
    cost += cumm_sum2[i]
    cost += cumm_sum1[n-1-i]

    old_min1 = min1
    if old_min1 >= cost:
        min1 = cost
        min2 = old_min1

    elif min2 > cost:
        min2 = cost

print min1 + min2



