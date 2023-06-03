#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    // DFS
    // 각 숫자를 선택하는 경우랑 선택하지 않는 경우 모두 탐색함
    // 재귀함수로 모든 가능한 조합을 탐색을 함
    void dfs(vector<int>& candidates, int target, int i, vector<int>& comb)
    {
        // target = 0 이 되는 순간 조합을 결과에 추가
        if (target == 0)
        {
            res.push_back(comb);
            return ;
        }
        // 세번째 인풋값때문에 추가함
        // i랑 candidates의 크기가 같을 경우랑 target이 0보다 작아서 만들지 못할경우
        if (i == candidates.size() || target < 0) return ;

        dfs(candidates, target, i + 1, comb);

        comb.push_back(candidates[i]);
        // 목표 합계를 줄이기 위해서 `target - candidates[i]` 처리
        dfs(candidates, target - candidates[i], i, comb);
        // 이전 단계에서 만든 조합이 중복되지 않기 위해 마지막 숫자를 pop해서 빼버림
        comb.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        dfs(candidates, target, 0, combination);
        return res;
    }
};

