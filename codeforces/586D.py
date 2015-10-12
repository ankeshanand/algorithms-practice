cases = int(raw_input())

def move1(l):
    nl = l
    for i, item in enumerate(l):
        if i == n-1:
            continue
        if l[i+1] != '.':
            nl = nl[:i] + l[i+1] + nl[i+1:]
        if l[i+1] == '.':
            nl = nl[:i] + l[i+1] + nl[i+1:]
    return nl

def possible(row, col, l1, l2, l3):
    if row < 0 or row > 2:
        return False
    if row == 0 and l1[col] != '.' and l1[col] != 's':
        print row, col
        return False

    if row == 1 and l2[col] != '.' and l2[col] != 's':
        print row, col
        return False

    if row == 2 and l3[col] != '.' and l3[col] != 's':
        print row, col
        return False

    if col == 25:
        return True
    col += 1
    l1 = move1(l1)
    l2 = move1(l2)
    l3 = move1(l3)
    if possible(row, col, l1, l2, l3):
        return True
    if possible(row-1, col, l1, l2, l3):
        return True
    if possible(row+1, col, l1, l2, l3):
        return True
    print row, col
    return False

for c in xrange(cases):
    n, k = map(int, raw_input().split())
    l1 = raw_input()
    l2 = raw_input()
    l3 = raw_input()
    row = -1
    if l1[0] == 's':
        row = 0
    elif l2[0] == 's':
        row = 1
    else:
        row = 2
    if possible(row, 0, l1, l2, l3):
        print 'YES'
    else:
        print 'NO'
