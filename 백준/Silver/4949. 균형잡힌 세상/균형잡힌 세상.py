import sys

while True:
    c = str(sys.stdin.readline().rstrip())
    stack = []

    if c == ".":
        break
    for i in c:
        if i == '(' or i == "[":
            stack.append(i)
        elif i == ')':
            if stack and stack[-1] == '(':
                stack.pop()
            else:
                stack.append(i)
                break
        elif i == ']':
            if stack and stack[-1] == '[':
                stack.pop()
            else:
                stack.append(i)
                break

    if stack:
        print("no")
    else:
        print("yes")
        
        