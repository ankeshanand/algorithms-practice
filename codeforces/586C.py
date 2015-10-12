n = int(raw_input())
v, d, p, r = [], [], [], []


def scan_reduce(idx, red, const):
    if idx > n:
        return
    for it in xrange(idx, n):
        if r[it] < 0 or red <= 0:
            continue
        p[it] -= red
        if const == 0:
            red -= 1
    for it in xrange(n):
        if r[it] < 0:
            continue
        if p[it] < 0:
            r[it] = -1
            scan_reduce(it+1, d[it], 1)
    return


for i in xrange(n):
    vi, di, pi = map(int, raw_input().split())
    v.append(vi)
    d.append(di)
    p.append(pi)
    r.append(1)

cured = []
count = 0
for i, item in enumerate(p):
    if p[i] < 0 or r[i] < 0:
        continue
    cured.append(i+1)
    count += 1
    r[i] = -1
    scan_reduce(idx=i+1, red=v[i], const=0)

print count
ans = ' '.join([str(x) for x in cured])
print ans
