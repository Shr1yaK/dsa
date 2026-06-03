class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            string s_copy = s;
            sort(s_copy.begin(), s_copy.end());

            mp[s_copy].push_back(s);
        }

        vector<vector<string>> result;

        for (auto pair : mp)
        {
            result.push_back(pair.second);
        }

        return result;
    }
};