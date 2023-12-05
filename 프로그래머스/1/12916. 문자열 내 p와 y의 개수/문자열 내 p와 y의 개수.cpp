#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int cnt = 0;

    for (int i = 0; s.size() > i; ++i)
    {
        s[i] = tolower(s[i]);
        if ('p' == s[i])
        {
            ++cnt;
        }
        else if ('y' == s[i])
        {
            --cnt;
        }
    }
    return cnt == 0 ? 1 : 0;
}