def dfs(idx, sum_taste = 0, sum_kcal = 0):
    global max_taste

    if sum_kcal > L:
        return

    if max_taste < sum_taste:
        max_taste = sum_taste

    if idx == N:
        return

    taste, kcal = data[idx]
    # 햄버거 재료 리스트에서 재료를 사용한경우
    dfs(idx + 1, sum_taste + taste, sum_kcal + kcal)
    # 아닌경우
    dfs(idx + 1, sum_taste, sum_kcal)


T = int(input())
for i in range(T):
    N, L = map(int, input().split())
    data = [list(map(int, input().split())) for _ in range(N)]
    maxTaste = 0
    dfs = (0, 0, 0)
    print(f"#{i} {maxTaste}")

