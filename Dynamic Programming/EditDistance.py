def EditDistance(A, B):
    D = [[None for _ in range(0, len(B) + 2)] for i in range(0, len(A) + 2)]

    for i in range(0, len(A) + 1):
        D[i][0] = i
    for i in range(0, len(B) + 1):
        D[0][i] = i

    for j in range(1, len(B) + 1):
        for i in range(1, len(A) + 1):
            insertion = D[i][j - 1] + 1
            deletion = D[i - 1][j] + 1
            match = D[i - 1][j - 1]
            mismatch = D[i - 1][j - 1] + 1
            # indices are subtracted by 1 during comparison as
            # the strings are stored index 1 onwards in the dp array
            # and hence i and j are moving 1 step ahead of the
            # actual indices of the string
            if A[i -1] == B[j -1]:
                D[i][j] = min(insertion, deletion, match)
            else:
                D[i][j] = min(insertion, deletion, mismatch)

    return D[(len(A))][len(B)]


if __name__ == "__main__":
    print(EditDistance(['E', 'D', 'I', 'T', 'I', 'N', 'G'], [
        'D', 'I', 'S', 'T', 'A', 'N', 'C', 'E']))
