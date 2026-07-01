class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        int n = columnNumber;
        char letter;
        string ans = "";
        while (n>0)
        {
            n--;
            letter = 'A' + (n%26);
            ans.push_back(letter);
            n/=26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};