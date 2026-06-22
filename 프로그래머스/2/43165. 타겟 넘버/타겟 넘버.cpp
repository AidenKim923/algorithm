#include <string>
#include <vector>

using namespace std;

void dfs(const vector<int>& numbers, int target, int index, int sum, int& answer)
{
    // 배열 전부 탐색한경우
    if (index == numbers.size())
    {
        if (sum == target) ++answer;
        return;
    }
    // 현재 인덱스의 숫자를 더하는 경우
    dfs(numbers, target, index + 1, sum + numbers[index], answer);

    // 현재 인덱스의 숫자를 빼는 경우
    dfs(numbers, target, index + 1, sum - numbers[index], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}