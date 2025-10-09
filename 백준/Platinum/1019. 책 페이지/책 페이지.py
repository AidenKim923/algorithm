import sys

def solve():
    n = int(sys.stdin.readline())
    ans = [0] * 10
    start, end, digit = 1, n, 1

    while start <= end:
        while end % 10 != 9 and start <= end:
            for c in str(end):
                ans[int(c)] += digit
            end -= 1

        if end < start:
            break

        while start % 10 != 0 and start <= end:
            for c in str(start):
                ans[int(c)] += digit
            start += 1

        if end < start:
            break

        start //= 10
        end //= 10
        count = end - start + 1

        for i in range(10):
            ans[i] += count * digit
        
        digit *= 10

    print(*ans)

if __name__ == "__main__":
    solve()