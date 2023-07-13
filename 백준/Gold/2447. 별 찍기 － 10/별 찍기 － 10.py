def draw_star(n):
    if n == 1:
        return '*'

    stars = draw_star(n//3)
    res = []

    for s in stars:
        res.append(s * 3)

    for s in stars:
        res.append(s + ' ' * (n // 3) + s)

    for s in stars:
        res.append(s * 3)

    return res

ans = draw_star(int(input()))
for a in ans:
    print(a)
    
    