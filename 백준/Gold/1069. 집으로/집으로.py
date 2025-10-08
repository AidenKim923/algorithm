import sys, math
input = sys.stdin.readline

x, y, d, t = map(int,input().split())
distance = math.sqrt(x**2 + y**2)

if distance >= d:
    ans = min(t * (distance // d) + distance % d, t * math.ceil(distance / d), distance)
else:
    ans = min(t + (d - distance), 2 * t, distance)

print(ans)