# Iterative algorithm


def knapsack(W, w, v):
    T = [0] * (W + 1)

    #  we fill the array for all weights from 1 to W
    for u in range(1, W + 1):
        # we start iterating through each of the objects' weights
        for i in range(len(w)):
            if w[i] <= u:
                T[u] = max(T[u], T[u - w[i]] + v[i])

    return T[W]


# prints 48 
print(knapsack(W=10, w=[6, 3, 4, 2], v=[30, 14, 16, 9]))
