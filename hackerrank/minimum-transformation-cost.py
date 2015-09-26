T = int(raw_input())

for t in xrange(T):
    X = raw_input()
    Y = raw_input()
    A, B, C = map(int, raw_input().split())
    X_dict, Y_dict = {}, {}
    D = min(A + B, C)
    total_cost = 0

    # Populate X dict
    for c in X:
        X_dict[c] = X_dict.get(c, 0) + 1
    # Populate U dict
    for c in Y:
        Y_dict[c] = Y_dict.get(c, 0) + 1

    # If size of X is greater, delete some chars from it
    if len(X) > len(Y):
        diff = len(X) - len(Y)
        while diff > 0:
            for c in X_dict:
                Y_dict[c] = Y_dict.get(c, 0)
                if X_dict[c] > Y_dict[c]:
                    if X_dict[c] - Y_dict[c] < diff:
                        diff -= X_dict[c] - Y_dict[c]
                        X_dict[c] = Y_dict[c]
                    else:
                        X_dict[c] -= diff
                        diff = 0
                    break
        total_cost += A * (len(X) - len(Y))

    # If the size of Y is greater, insert some cbars into X
    if len(Y) > len(X):
        diff = len(Y) - len(X)
        while diff > 0:
            for c in Y_dict:
                X_dict[c] = X_dict.get(c, 0)
                if Y_dict[c] > X_dict[c]:
                    if Y_dict[c] - X_dict[c] < diff:
                        diff -= Y_dict[c] - X_dict[c]
                        X_dict[c] = Y_dict[c]
                    else:
                        X_dict[c] += diff
                        diff = 0
                    break
        total_cost += B * (len(Y) - len(X))

    # Real stuff
    common_letters = 0
    for c in X_dict:
        Y_dict[c] = Y_dict.get(c, 0)
        common_letters += min(X_dict[c], Y_dict[c])

    replacements = len(Y) - common_letters
    total_cost += D * replacements
    print total_cost

