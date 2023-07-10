cnt = int(input())
stk = []

for i in range(cnt): 
    num = int(input())
    if(num == 0):
        stk.pop()
    else:
        stk.append(num)
print(sum(stk))

