T = int(input())
for i in range(0, T):
    N = int(input())
    K = int(input())
    if N == K:
        print("0")
    elif K > N:
        a = K // N
        aFreq = K % N
        b = a - 1
        bFreq = N - aFreq
        if aFreq == bFreq:
            print(str((2*aFreq) - 1))
        else:
            print(str(2*bFreq) if aFreq > bFreq else str(2*aFreq))
    else:
        if K > N // 2:
            print(str((N - K) * 2))
        elif K < N // 2:
            print(str(K * 2))
        else:
            if N % 2 == 0:
                print(str((2*K) - 1))
            else:
                print(str(2*K))