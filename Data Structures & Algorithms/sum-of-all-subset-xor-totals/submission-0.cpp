class Solution {
public:

    int ans= 0;
    void dfs(int index, vector<int>& nums, int xr)
    {
        if (index == nums.size())
        {
            ans += xr;
            return;
        }

        dfs(index + 1, nums, xr ^ nums[index]); //take current number

        dfs(index + 1, nums, xr); //skip current number
    }
    int subsetXORSum(vector<int>& nums) 
    {
        dfs(0, nums, 0);
        return ans;
    }
};