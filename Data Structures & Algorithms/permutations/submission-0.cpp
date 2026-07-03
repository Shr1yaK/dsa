class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<bool>& visited, vector<int>& current, vector<int>& nums)
    {
        if (current.size()==nums.size())
        {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i<nums.size(); i++)
        {
            if (visited[i]) continue;
            visited[i] = true;
            current.push_back(nums[i]);
            
            dfs(visited,current,nums);

            current.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector <int> current;
        vector<bool> visited(nums.size(), false);
        dfs(visited,current,nums);

        return ans;    
    }
};