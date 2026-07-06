class Solution {
public:
    vector<string> ans;
    void dfs(string& current, int open, int close, int n)
    {
        if (open == n && close == n)
        {
            ans.push_back(current);
            return;
        }
        if (open < n)
        {
            current.push_back('(');
            dfs(current, open + 1, close, n);
            current.pop_back();
        }

        if (close < open)
        {
            current.push_back(')');
            dfs(current, open, close + 1, n);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        string current = "";
        dfs(current, 0, 0, n);
        return ans;
    }
};