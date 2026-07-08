class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int index, vector<int>& current)
    {
        ans.push_back(current);
        for (int i = index; i<nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i-1])  continue;
            current.push_back(nums[i]);
            dfs (nums, i+1, current);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int>current;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, current);
        return ans;
    }
};