# WRONG SOLUTION

T = int(input())
for i in range(0, T):
    N = int(input())
    K = int(input())
    A = [0] * N
    i = 0
    while K > 0:
        A[i] += 1
        K -= 1
        i = (i + 1) % N
    # print(A)
    B = [0] * N
    i = 0
    # for num in A:
    #     # print("i = " + str(i))
    #     if B[i] == 0:
    #         B[i] = num
    #     else:
    #         i += 1
    #         B[i] = num
    #     i = (i + 2) % N
    j = 0
    for i in range (0, N, 2):
        B[i] = A[j]
        i += 2
        j += 1
        # print("j = " + str(j))
    if N % 2 != 0:
        j -= 1
    for i in range (N-1, 0, -2):
        # print("    i = " + str(i))
        # print("    j = " + str(j))
        B[i] = A[j]
        j += 1
    #     print(B)
    # print(B)
    ans = 0
    for i in range(0, N - 1):
        ans += abs(B[i] - B[i + 1])
    print(ans)