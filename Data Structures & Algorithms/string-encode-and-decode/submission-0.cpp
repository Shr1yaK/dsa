class Solution {
public:

    string encode(vector<string>& strs) 
    {
        if (strs.empty())
            return "";
        
        string encoded;
        for (string s : strs)
        {
            encoded += to_string(s.length()) + "#" + s;
        }
        
        return encoded;
    }

    vector<string> decode(string s) 
    {
        if (s.empty())
            return {};

        vector<string> ans;
        int i = 0;
        while (i<s.length())
        {
            int j = i;

            while (s[j] != '#')
                j++;

            int len = stoi(s.substr(i, j - i));

            string word = s.substr(j + 1, len);

            ans.push_back(word);

            i = j + 1 + len;
        }

        return ans;
    }
};
