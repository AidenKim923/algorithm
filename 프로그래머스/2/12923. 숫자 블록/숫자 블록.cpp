#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1);
    for (int i = 0; answer.size() > i; ++i)
    {
        long long number = begin + i;
        for (long long j = 2; sqrt(number) >= j; ++j)
        {
            if (number % j == 0)
            {
                if (number / j > 10000000)
                {
                    answer[i] = j;
                }
                else
                {
                    answer[i] = number / j;
                    break;
                }
            }
		}
        if (answer[i] == 0)
        {
			answer[i] = 1;
		}
    }
    if (begin == 1)
    {
        answer[0] = 0;
    }
    return answer;
    
}