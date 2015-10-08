n, t = map(int, raw_input().split())

import sys

if n == 1 and t == 10:
    print -1
    sys.exit(0)

if t == 10:
    print ('1' * (n-1)) + '0'

else:
    print str(t) * n
