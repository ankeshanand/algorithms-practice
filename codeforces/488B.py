import sys

n = int(raw_input())
a = []
for i in xrange(n):
    a.append(int(raw_input()))

a.sort()

if n == 1:
    print 'YES'
    print a[0]*2
    print a[0]*2
    print a[0]*3
    sys.exit(0)

if n == 4:
    if a[3] != 3*a[0]:
        print 'NO'
        sys.exit(0)
    if a[1] + a[2] != 4*a[0]:
        print 'NO'
        sys.exit(0)
    print 'YES'
    sys.exit(0)

if n == 2:
    if a[1] == 3*a[0]:
        print 'YES'
        print 2*a[0]
        print 2*a[0]
        sys.exit(0)
    if 4*a[0] - a[1] <= 0:
        print 'NO'
        sys.exit(0)
    print 'YES'
    print 4*a[0] - a[1]
    print 3*a[0]
    sys.exit(0)

if n == 3:
    if a[2] == 3*a[0]:
        print 'YES'
        print 4*a[0] - a[1]
        sys.exit(0)
    if a[1] + a[2] == 4*a[0]:
        print 'YES'
        print 3*a[0]
        sys.exit(0)
    if (a[0] + a[1]) % 4 == 0 and a[2] % 3 == 0 and (a[0] + a[1]) * 3 == a[2] * 4:
        print 'YES'
        print a[2]/3
        sys.exit(0)
    print 'NO'
    sys.exit(0)

if n == 0:
    print 'YES'
    print 1
    print 1
    print 3
    print 3
    sys.exit(0)

#dasd
