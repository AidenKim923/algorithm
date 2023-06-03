class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& result, int begin) {
        if (begin >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            swap(nums[i], nums[begin]);
            dfs(nums, result, begin + 1);
            swap(nums[i], nums[begin]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, result, 0);
        return result;
    }
};