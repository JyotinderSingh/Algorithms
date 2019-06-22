r1 = "qwertyuiop"
r2 = "asdfghjkl;"
r3 = "zxcvbnm,./"

dir = input()
sequence = input()

shift = ""

if dir == 'R':
    shift = -1
else:
    shift = 1

result = ""

for ch in sequence:
    if ch in r1:
        result += r1[r1.find(ch) + shift]
    elif ch in r2:
        result += r2[r2.find(ch) + shift]
    else:
        result += r3[r3.find(ch) + shift]

print(result)