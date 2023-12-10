def replace_code(s):
    return s.replace("C#", "I").replace("D#", "J").replace("F#", "K").replace("G#", "L").replace("A#", "H")


def solution(m, musicinfos):
    answer = '(None)'
    m = replace_code(m)
    max_time = 0

    for info in musicinfos:
        start, end, title, melody = info.split(',')
        start = start.split(':')
        end = end.split(':')
        time = (int(end[0]) - int(start[0])) * 60 + int(end[1]) - int(start[1])
        melody = replace_code(melody)
        melody = melody * (time // len(melody)) + melody[0:time % len(melody)]

        if m in melody and time > max_time:
            max_time = time
            answer = title

    return answer