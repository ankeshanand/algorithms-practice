def recurse(i, A):
    global MAX
    if i == len(A) - 1:
        s = compute_s(list(A))
        if s > MAX:
            MAX = s
        return

    recurse(i+1, list(A))
    if iseven(A[i-1]) and iseven(A[i+1]):
        A[i] = (A[i-1] + A[i+1]) / 2
        recurse(i+1, list(A))

def compute_s(A):
    i, j = 0, len(A) - 1
    s = 0
    while i < j:
        s += abs(A[i] - A[j])
        i += 1
        j -= 1
    return s

def iseven(x):
    return x % 2 == 0

T = int(raw_input())
MAX = 0
for t in xrange(T):
    N = int(raw_input())
    P = [int(x) for x in raw_input().split()]
    recurse(1, list(P))
    print MAX
    MAX = 0


