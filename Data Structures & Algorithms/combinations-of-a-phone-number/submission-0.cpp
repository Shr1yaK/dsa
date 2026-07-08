class Solution {
public:
    vector<string>ans;
    void dfs(string digits, vector<string>& keypad, string current, int index)
    {
        if (index == digits.size())
        {
            ans.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        for (char ch : keypad[digit])
        {
            current.push_back(ch);
            dfs(digits, keypad, current, index+1);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty())
            return {};
            
        vector<string> keypad = 
        {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        string current = "";
        dfs(digits, keypad, current,0);
        return ans;
    }
};