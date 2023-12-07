#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;

    for (int i = 1; n > i; ++i)
    {
        int sum = i;
        for (int j = i + 1; n > j; ++j)
        {
            sum += j;
            if (sum == n)
            {
                ++answer;
			}
			else if (sum > n)
				break;
        }
    }

    return answer;
}