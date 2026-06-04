class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set <char> seen;
        int left = 0;
        int maxsizewindow = 0;
        for (int right = 0; right<s.size(); right++)
        {
            while(seen.find(s[right]) != seen.end())
            {
                seen.erase(s[left]);
                left++;
                
            }

            int currwindow = right - left +1;
            maxsizewindow = max (currwindow, maxsizewindow);
            seen.insert(s[right]);
        }

        return maxsizewindow;
    }
};