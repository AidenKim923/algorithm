#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long factorial(int n) 
{
	if ( n == 0) return 1;
    return n * factorial(n - 1);
}

void getPermutation(vector<int>& v, vector<int>& answer, long long k) 
{
    if (v.size() == 1) 
	{
		answer.push_back(v[0]);
		return;
	}

	long long fact = factorial(v.size() - 1);
	for (int i = 1; v.size() >= i; ++i)
	{
		if ((fact * i) >= k)
		{
			answer.push_back(v[i - 1]);
			v.erase(v.begin() + i - 1);
			getPermutation(v, answer, k - fact * (i - 1));
		}
	}
}

vector<int> solution(int n, long long k) {
    vector<int> answer;

	vector<int> v(n);
	for (int i = 0; n > i; ++i)
	{
		v[i] = i + 1;
	}

	getPermutation(v, answer, k);

    return answer;
}