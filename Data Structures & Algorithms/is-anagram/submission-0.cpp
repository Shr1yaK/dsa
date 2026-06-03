// hashing
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map <char, int> freq;
        
        for (char c : s)
            freq[c]++;

        for (char d : t)
            freq[d]--;

        for (auto pair : freq)
        {
            if (pair.second != 0)
                return false;
        }

        return true;
    }
};