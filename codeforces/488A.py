n = int(raw_input())
n += 1
s = str(n)
count = 1

while '8' not in s:
    n += 1
    s = str(n)
    count += 1

print count
