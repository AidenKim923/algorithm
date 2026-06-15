#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static const char* SOUNDS[4]   = { "aya", "ye", "woo", "ma" };
static const int SOUND_LEN[4] = { 3, 2, 3, 2 };

bool CanSpeak(const char* word)
{
    int len = (int)strlen(word);
    int i = 0;
    int prevIndex = -1;

    while (i < len)
    {
        int matched = -1;

        for (int s = 0; s < 4; ++s)
        {
            int soundLen = SOUND_LEN[s];

            if ((i + soundLen <= len) && (strncmp(word + i, SOUNDS[s], soundLen) == 0))
            {
                matched = s;
                break;
            }
        }
        
        if ((matched == -1) || (matched == prevIndex))
            return false;

        i += SOUND_LEN[matched];
        prevIndex = matched;
    }

    return true;
}

int solution(const char* babbling[], size_t babbling_len)
{
    int answer = 0;

    for (size_t i = 0; i < babbling_len; ++i)
    {
        if (CanSpeak(babbling[i]))
            ++answer;
    }

    return answer;
}
