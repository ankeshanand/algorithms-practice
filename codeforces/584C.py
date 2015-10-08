n, t = map(int, raw_input().split())
all_chars = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
s1 = raw_input()
s2 = raw_input()

common = 0
same = []
for i in xrange(n):
    if s1[i] == s2[i]:
        common += 1
        same.append(i)

import sys
if 2*n - 2*t - common > n:
    print -1
    sys.exit(0)

p = n - t

if p < common:
    to_del = common - p
    for i in xrange(to_del):
        index = same[i]
        for item in all_chars:
            if item != all_chars[i]:
                item1 = item
                break
        item2 = list(set(all_chars) - set([item1]))[0]
        s1[index] = item1
        s2[index] = item2
        same.remove(index)

p -= common

index = 0
count = 0
i = 0
new = ''
while i < p:
    if index not in same:
        if count % 2 == 0:
            new = new + s1[index]
            count += 1
            index += 1
        else:
            new = new + s2[index]
            count += 1
            index += 1
            i += 1
for item in same:
    new = new[:item] + s1[item] + new[item+1:]
print new


