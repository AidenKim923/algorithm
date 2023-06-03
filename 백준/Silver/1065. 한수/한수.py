n = int(input())
print(sum([(n < 100) or (n // 100 + n%10 == 2*(n//10 % 10)) for n in range(1, n+1)]))

