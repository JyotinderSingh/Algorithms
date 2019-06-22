n, m = input().split()
n = int(n)
m = int(m)
ctr = 0
while m > n:
    if m%2 == 1:
        m += 1
        ctr += 1
    else:
        m //= 2
        ctr += 1

ctr += n-m
print(ctr)