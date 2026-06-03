// frequencyarray
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size()!=t.size()) return false;

        vector <int> freq (26,0);
        int idx;
        for (int i = 0; i<s.size(); i++)
        {
            idx = s[i]-'a';
            freq[idx]++;
        }

        for (int j = 0; j<t.size(); j++)
        {
            idx = t[j]-'a';
            freq[idx]--;
        }

        for (int k = 0; k<26; k++)
        {
            if (freq[k]!=0) return false;
        }

        return true;
    }
};