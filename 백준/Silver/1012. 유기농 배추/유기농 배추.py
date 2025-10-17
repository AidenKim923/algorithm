import sys
from collections import deque
input = sys.stdin.readline

dx = [0,0,-1,1]
dy = [-1,1,0,0]

def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    visited[x][y] = 1

    while queue:
        a, b = queue.popleft()
        for i in range(4):
            nx = a + dx[i]
            ny = b + dy[i]
            if 0 <= nx < N and 0 <= ny < M:
                if graph[nx][ny] == 1 and visited[nx][ny] == 0:
                    visited[nx][ny] = 1
                    queue.append((nx, ny))      


for _ in range(int(input())):
    M, N, K = map(int, input().split())
    graph = [[0] * M for _ in range(N)]
    visited = [[0] * M for _ in range(N)]
    for _ in range(K):
        a, b = map(int, input().split())
        graph[b][a] = 1
    cnt = 0
    for i in range(N):
        for j in range(M):
            if graph[i][j] == 1 and visited[i][j] == 0:
                bfs(i, j)
                cnt += 1
    print(cnt)
    