def solution(n, words):
    for i, (current, next_word) in enumerate(zip(words, words[1:]), start=1):
        if current[-1] != next_word[0] or next_word in words[:i]:
            return [(i % n) + 1, (i // n) + 1]
    else:
        return [0, 0]