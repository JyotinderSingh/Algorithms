def isBalanced(str):
    stack = []
    for char in str:
        if char in ['(', '[']:
            stack.append(char)
        else:
            if len(stack) == 0:
                return False
            top = stack.pop()
            if (top is '[' and char is not ']') or (top is '(' and char is not ')'):
                return False
    return (len(stack) == 0)

print(isBalanced("()[()()]"))
