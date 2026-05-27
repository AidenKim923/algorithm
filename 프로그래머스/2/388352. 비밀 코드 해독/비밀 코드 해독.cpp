#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool check(int pwd, const vector<int>& compare, const vector<int>& ans)
{
    for (int i = 0; i < (int)compare.size(); ++i)
    {
        if (__builtin_popcount(pwd & compare[i]) != ans[i]) return false;
    }
    return true;
}

int solution(int n, vector<vector<int>> q, vector<int> ans)
{
    const int qSize = (int)q.size();
    vector<int> compare(qSize);
    for (int i = 0; i < qSize; ++i)
        for (int bit : q[i]) compare[i] |= (1 << (bit - 1));

    constexpr int K = 5;
    const int limit = (1 << n);

    int answer = 0;
    int mask = (1 << K) - 1;

    while (mask < limit)
    {
        if (check(mask, compare, ans))
            ++answer;

        const int c = mask & -mask;
        const int r = mask + c;
        mask = (((r ^ mask) >> 2) / c) | r;
    }

    return answer;
}