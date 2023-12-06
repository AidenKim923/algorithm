#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>> dp(land.size(), vector<int>(4));

    for (int i = 0; 4 > i; ++i)
    {
        dp[0][i] = land[0][i];
    }

    for (int i = 1; land.size() > i; ++i)
    {
        for (int j = 0; 4 > j; ++j)
        {
			int max = 0;
            for (int k = 0; 4 > k; ++k)
            {
                if (k == j)
                {
					continue;
				}
                if (max < dp[i - 1][k])
                {
					max = dp[i - 1][k];
				}
			}
			dp[i][j] = land[i][j] + max;
		}
    }
    answer = *max_element(dp.back().begin(), dp.back().end());
    return answer;

}