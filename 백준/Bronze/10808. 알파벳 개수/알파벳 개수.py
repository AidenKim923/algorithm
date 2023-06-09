S = input()
cnt = [0]*26

for i in S:
    cnt[ord(i)-97] += 1

print(*cnt)

