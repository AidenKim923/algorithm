import sys

s1 = list(sys.stdin.readline().rstrip())
s2 = []

n = int(sys.stdin.readline())

for _ in range(n):
    cmd = sys.stdin.readline().split()
    if cmd[0] == 'L' and s1:
        s2.append(s1.pop())
    elif cmd[0] == 'D' and s2:
        s1.append(s2.pop())
    elif cmd[0] == 'B' and s1:
        s1.pop()
    elif cmd[0] == 'P':
        s1.append(cmd[1])

print("".join(s1 + list(reversed(s2))))
            
            