#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) 
{
	vector<int> answer;

    for (auto i : arr) {
		if (0 == (i % divisor)) 
		{
			printf("%d ", i);
			answer.push_back(i);
		}
	}
	if (answer.empty())
	{
		answer.push_back(-1);
	}
	sort(answer.begin(), answer.end());
	return answer;
}