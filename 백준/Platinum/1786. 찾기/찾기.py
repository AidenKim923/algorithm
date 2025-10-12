import sys
input = sys.stdin.readline

def get_pi(pattern):
    m = len(pattern)
    pi = [0] * m
    j = 0

    for i in range(1, m):
        while j > 0 and pattern[i] != pattern[j]:
            j = pi[j - 1]

        if pattern[i] == pattern[j]:
            j += 1
            pi[i] = j

    return pi

def kmp(text, pattern):
    n = len(text)
    m = len(pattern)
    pi = get_pi(pattern)

    positions = []
    j = 0

    for i in range(n):
        while j > 0 and text[i] != pattern[j]:
            j = pi[j - 1]

        if text[i] == pattern[j]:
            if j == m - 1:
                positions.append(i - m + 2)
                j = pi[j]
            else:
                j += 1

    return positions

T = input().rstrip()
P = input().rstrip()

result = kmp(T, P)

print(len(result))
if result:
    print(*result)

