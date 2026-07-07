class Solution {
public:
    vector<vector<int>> ans;
    void dfs (vector<int>& candidates, int target, int sum, vector<int>& current, int index)
    {
        if (sum==target)
        {
            ans.push_back(current);
            return;
        }

        if (sum>target) return;
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            
            if (sum + candidates[i] > target)   break;

            // Choose
            current.push_back(candidates[i]);

            // Recurse with i + 1
            dfs(candidates, target, sum+candidates[i], current, i+1);

            // Undo
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<int> current; 
        dfs(candidates, target, 0, current, 0);
        return ans;   
    }
};