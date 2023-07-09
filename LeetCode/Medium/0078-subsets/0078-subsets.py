class Solution:
    def subsets(self, nums):
        res = []

        def dfs(start, visited):
            res.append(visited)
            for idx in range(start, len(nums)):
                dfs(idx + 1, visited + [nums[idx]])

        dfs(0, [])
        return res

    