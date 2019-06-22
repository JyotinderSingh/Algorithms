# A. Initial Bet

a, b, c, d, e = input().split()
a = int(a)
b = int(b)
c = int(c)
d = int(d)
e = int(e)

if ((a+b+c+d+e)%5 == 0) and a+b+c+d+e != 0:
    print(int((a+b+c+d+e)/5))
else:
    print("-1")