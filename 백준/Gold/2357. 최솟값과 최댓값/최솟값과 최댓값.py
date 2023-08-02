import sys

input = sys.stdin.readline

N, M = map(int, input().split())
lst = [int(input()) for _ in range(N)]
tree = [[1000000000, 1] for _ in range(4 * N)]


def init(start, end, idx):
    if start == end:
        tree[idx] = [lst[start], lst[start]]
        return tree[idx]
    mid = (start + end) // 2
    l, r = init(start, mid, idx * 2), init(mid + 1, end, idx * 2 + 1)
    tree[idx] = [min(l[0], r[0]), max(l[1], r[1])]
    return tree[idx]


def interval_minmax(start, end, idx, left, right):
    if left > end or right < start:
        return [1000000000, 0]
    if left <= start and right >= end:
        return tree[idx]
    mid = (start + end) // 2
    l, r = interval_minmax(start, mid, idx * 2, left, right), interval_minmax(mid + 1, end, idx * 2 + 1, left, right)
    return [min(l[0], r[0]), max(l[1], r[1])]


init(0, N - 1, 1)
for _ in range(M):
    a, b = map(int, input().split())
    print(*interval_minmax(0, N - 1, 1, a - 1, b - 1), end="\n")
    