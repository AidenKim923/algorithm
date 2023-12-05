#include <string>
#include <vector>

using namespace std;

int CountOne(int n)
{
    int cnt = 0;
    for (int i = 0; 21 > i; ++i)
    {
        if ((0x01 << i) & n)
        {
            ++cnt;
        }
    }
    return cnt;
}

int solution(int n) {
    int answer = CountOne(n);
    while (CountOne(++n) != answer);
    return n;
}