s = input()


def subseq(s, sub):
    # find sub in s as a subseq
    last = - 1
    for ch in sub:
        last = s.find(ch, last+1)
        if last < 0:
            return False
    return True


for e in range(0, 1001, 8):
    if subseq(s, str(e)):
        print('YES')
        print(e)
        exit(0)
print('NO')
