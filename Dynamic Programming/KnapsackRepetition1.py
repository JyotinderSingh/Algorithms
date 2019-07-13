# Recursive algorithm
T = dict()


def knapsack(w, v, u):
    # if the current requested weight is not yet present in the dictionary
    # make a new entry and initialize the max value at 0
    if u not in T:
        T[u] = 0

        # Iterate through the whole list of objects
        for i in range(len(w)):
            # if the weight of the current obj is
            # less than the total available capacity
            if w[i] <= u:
                T[u] = max(T[u], knapsack(w, v, u - w[i]) + v[i])

    return T[u]


# prints 48
print(knapsack(w=[6, 3, 4, 2], v=[30, 14, 16, 9], u=10))
