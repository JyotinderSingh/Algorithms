T = int(input())
ans = []
for i in range (0, T):
    N = int(input())
    numbers = list(map(int, input().split()))
    summation = sum(numbers)
    mean = summation / N
    rem = summation - (mean * (N - 1))
    # print("rem = " + str(rem))
    if rem in numbers:            
        ans.append(numbers.index(rem) + 1)
    else:
        ans.append("Impossible")
for i in ans:
    print(i)