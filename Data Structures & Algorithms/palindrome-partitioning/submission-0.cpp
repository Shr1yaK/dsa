class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string subpart)
    {
        int left = 0;
        int right = subpart.size() - 1;
        while (left <=right)
        {
            if (subpart[left]!=subpart[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void dfs(string& s, int index, vector<string>& current)
    {
        if (index == s.size())
        {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            string subpart = s.substr(index, i - index + 1);

            if (!isPalindrome(subpart)) continue;

            current.push_back(subpart); //choose
            dfs(s, i + 1, current);
            current.pop_back(); //undo
        }
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<string> current;
        dfs(s, 0, current);
        return ans;
    }
};