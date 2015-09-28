a, b = map(int, raw_input().split())

d1 = min(a,b)
d2 = max(a,b) - min(a,b)

d2 = d2 / 2

print d1, d2
