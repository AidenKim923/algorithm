from collections import deque
import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    p = input().rstrip()
    n = int(input())
    arr_str = input().rstrip()
    
    if n == 0:
        arr = deque()
    else:
        arr = deque(arr_str[1:-1].split(','))
    
    is_reversed = False
    err = False

    for cmd in p:
        if cmd == 'R':
            is_reversed = not is_reversed
        elif cmd == 'D':
            if not arr:
                err = True
                break
            if is_reversed:
                arr.pop()
            else:
                arr.popleft()

    if err:
        print("error")
    else:
        if is_reversed:
            arr.reverse()
        print('[' + ','.join(arr) + ']')
