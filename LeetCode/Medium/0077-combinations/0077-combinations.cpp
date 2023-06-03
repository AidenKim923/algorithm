class Solution {
public:
    void combi(int n, int k, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i <= n; ++i) {
            combination.push_back(i);
            combi(n, k, i + 1, combination, result);
            combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        combi(n, k, 1, combination, result);
        return result;
    }
};