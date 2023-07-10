def is_vps():
    T = int(input())
    for _ in range(T):
        data = list(map(str, input()))
        sum = 0
        for i in data:
            if i == "(":
                sum += 1
            elif i == ")":
                sum -= 1
            if sum < 0:
                print("NO")
                break
        if sum == 0:
            print("YES")
        elif sum > 0:
            print("NO")


if __name__ == "__main__":
    is_vps()
    
    