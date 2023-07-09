class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(curr, curr_sum):
            if curr_sum > target:
                return
            if curr_sum == target:
                result.append(path[:])
                return

            for val in curr:
                path.append(val)
                dfs(candidates[candidates.index(val) :], sum(path))
                path.pop()

        path, result = [], []
        dfs(candidates, 0)
        return result

    