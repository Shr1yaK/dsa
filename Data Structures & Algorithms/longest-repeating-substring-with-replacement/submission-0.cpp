class Solution {
public:
    int characterReplacement(string s, int k) 
    {   
        int left = 0;
        int maxfreq=0;
        int maxwindow=0;
        vector <int> freq (26,0);
        for (int right = 0; right<s.size(); right++)
        {
            freq[s[right] - 'A']++;
            maxfreq=max(maxfreq, freq[s[right] - 'A']);
            while ((right-left+1)-maxfreq>k)
            {
                freq[s[left]-'A']--;
                left++;
            }
            maxwindow = max(maxwindow, right - left + 1);
        }
        return maxwindow;
    }
};