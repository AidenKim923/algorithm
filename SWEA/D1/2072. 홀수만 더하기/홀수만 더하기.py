T = int(input())
res = []
sum = 0
for i in range(T):
    res = map(int, input().split())
    for r in res:
        if r % 2 == 0:
            pass
        else:
            sum += r
    print(f"#{i + 1} {sum}")
    sum = 0

