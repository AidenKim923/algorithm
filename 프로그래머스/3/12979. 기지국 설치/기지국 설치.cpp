#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1, index = 0;

    while (n >= start)
    {
        if ((start >= (stations[index] - w)) && (start <= (stations[index] + w)))
        {
			start = stations[index] + w ;
			index++;
		}
        else
        {
			start += 2 * w;
			answer++;
		}
        start++;
    }

    return answer;
}
