class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int index, vector<int>& nums, vector<int>& current)
    {
        if (index == nums.size())
        {
            ans.push_back(current);
            return;
        }
        // Take
        current.push_back(nums[index]);
        dfs(index + 1, nums, current);

        // Undo
        current.pop_back();

        // Skip
        dfs(index + 1, nums, current);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> current;
        dfs(0, nums, current);
        return ans;
    }
};