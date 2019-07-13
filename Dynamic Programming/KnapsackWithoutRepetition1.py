# Recursive Algorithm

T = dict()


def knapsack(w, v, u, i):
    # Entry for knapsack with weight u
    # made from the first i items
    if (u, i) not in T:
        if i == 0:
            T[u, i] = 0
        else:
            T[u, i] = knapsack(w, v, u, i - 1)
            if u >= w[i-1]:
                T[u, i] = max(T[u, i], knapsack(
                    w, v, u - w[i - 1], i - 1) + v[i - 1])

    return T[u, i]


print(knapsack(w=[6, 3, 4, 2], v=[30, 14, 16, 9], u=10, i=4))
