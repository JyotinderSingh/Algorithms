from functools import reduce

n = int(input())
divs = [int(x) for x in input().split()]
num1 = max(divs)
divs.remove(num1)
divs = [item for item in divs if item not in list(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))]
# print(divs)
num2 = max(divs)
print(num1, num2)