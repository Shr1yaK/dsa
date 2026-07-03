class Solution {
public:
    vector<vector<int>> ans;
    void dfs (vector<int>&current, int index, int target, int sum, vector<int>& candidates)
    {
        if (sum == target)
        {
            ans.push_back(current);
            return;
        }

        if (sum > target)
            return;

        if (index == candidates.size())
            return;

        current.push_back(candidates[index]);
        dfs (current, index, target, sum+candidates[index], candidates);

        current.pop_back();
        dfs (current, index+1, target, sum, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int>current;
        dfs(current, 0, target, 0, candidates);
        return ans;
    }
};