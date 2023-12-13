#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int s = 0, e = 0;
    int sum = sequence[0];
    int sublength = sequence.size() + 1;
    pair<int, int> answer;

    while ((e >= s) && (sequence.size() > e))
    {
        if (sum < k)
        {
			sum += sequence[++e];
		}
        else if (sum == k)
        {
            if (sublength > (e - s + 1))
            {
                sublength = e - s + 1;
                answer = { s, e };
            }
            else if ((sublength == (e - s + 1)))
            {
                if (answer.first > s)
                {
                    answer = { s, e };
                }
            }
            sum -= sequence[s++];
		}
        else
        {
           sum -= sequence[s++];
		}
	}
    return { answer.first, answer.second };
}
