T = dict()

def lis(A, i):
    if i not in T:
        T[i] = 1

        for j in range(i):
            if A[j] < A[i]:
                T[i] = max(T[i], lis(A, j) + 1)

    return T[i]


A = [7, 2, 1, 3, 8, 4, 9, 1, 2, 6, 5, 9, 3]
print(max(lis(A, i) for i in range(len(A))))