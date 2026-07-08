class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int index, vector<int>& current, int n, int k)
    {
        if (current.size()==k)
        {
            ans.push_back(current);
            return;
        }

        for (int i = index; i<=n; i++)
        {
            current.push_back(i);
            dfs(i+1,current,n,k);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> current;
        dfs(1,current,n,k);
        return ans;
    }
};