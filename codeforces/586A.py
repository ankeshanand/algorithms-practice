n = int(raw_input())
a = [int(x) for x in raw_input().split()]

start = 0
for i, item in enumerate(a):
    if item == 1:
        break
    start += 1

end = len(a)
for i, item in enumerate(reversed(a)):
    if item == 1:
        break
    end -= 1

a = a[start:end]

zeroes = 0

i = 0

while i < len(a):
    if a[i] == 0:
        clen = 0
        while a[i] == 0:
            clen += 1
            i += 1
            if i >= len(a):
                break
        if clen > 1:
            zeroes += clen
    i += 1

print len(a) - zeroes


