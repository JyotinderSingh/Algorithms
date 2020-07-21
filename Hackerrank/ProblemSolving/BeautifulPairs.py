from collections import Counter
n = int(input())
a, b = map(int, input().split()), map(int, input().split())
ca, cb = Counter(a), Counter(b)
common = sum(min(ca[k], cb[k]) for k in ca.keys())
print(common-1 if common == n else common+1)
