def solution(msg):
    answer = []
    d = dict()
    for c in range(ord('A'), ord('Z')+1):
        d[chr(c)] = c - ord('A') + 1
    index = 27
    start, end = 0, 1

    while end < len(msg) + 1:
        s = msg[start:end]
        if s not in d:
            answer.append(d[s[:-1]])
            d[s] = index
            index += 1
            start = end - 1
        else:
            end += 1
    answer.append(d[msg[start:]])
    return answer