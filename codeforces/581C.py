n, k = map(int, raw_input().split())

a = [int(x) for x in raw_input().split()]
studs = 0
for item in a:
    if item == 100:
        studs += 1
a = [x for x in a if x != 100]

mods = [(x % 10, i) for i, x in enumerate(a)]
mods.sort(reverse=True)

for item in mods:
    if k <= 0:
        break
    old_a_item = a[item[1]]
    a[item[1]] += min(k, 10 - item[0])
    k -= min(k, 10 - item[0])
    if a[item[1]] / 10 == old_a_item / 10:
        k += old_a_item - a[item[1]]
        a[item[1]] = old_a_item

if k > 0:
    for i, item in enumerate(a):
        if k <= 0:
            break
        if k >= 100 - item:
            k -= 100 - item
            a[i] = 100
        else:
            a[i] += k
            k = 0
            k += a[i] % 10
            a[i] -= a[i] % 10

total = 10 * studs

for item in a:
    total += item / 10

print total



