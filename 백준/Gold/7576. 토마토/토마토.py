import sys
from collections import deque

m, n = map(int, sys.stdin.readline().split())
box = []
queue = deque()
unripe = 0

for i in range(n):
    row = list(map(int, sys.stdin.readline().split()))
    for j in range(m):
        if row[j] == 1:
            queue.append((i, j))
        elif row[j] == 0:
            unripe += 1
    box.append(row)

if unripe == 0:
    print(0)
    exit()

directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
days = 0

while queue:
    for _ in range(len(queue)):
        x, y = queue.popleft()
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and box[nx][ny] == 0:
                box[nx][ny] = 1
                unripe -= 1
                queue.append((nx, ny))
    if queue:
        days += 1

print(days if unripe == 0 else -1)
