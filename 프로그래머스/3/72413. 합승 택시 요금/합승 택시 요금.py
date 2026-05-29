def solution(n, s, a, b, fares):
    INF = float('inf')

    maps = [[INF] * (n + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        maps[i][i] = 0

    for node1, node2, fare in fares:
        maps[node1][node2] = fare
        maps[node2][node1] = fare

    for k in range(1, n + 1):
        for i in range(1, n + 1):
            if maps[i][k] == INF:
                continue
            for j in range(1, n + 1):
                new_dist = maps[i][k] + maps[k][j]
                if new_dist < maps[i][j]:
                    maps[i][j] = new_dist

    return min((maps[s][t] + maps[t][a] + maps[t][b]) for t in range(1, n + 1))