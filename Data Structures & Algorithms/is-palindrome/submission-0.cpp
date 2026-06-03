class Solution {
public:
    bool isPalindrome(string s) 
    {
        int n = s.size();
        // cout <<n;
        
        string t;
        // int j = 0;
        for (int i = 0; i<n; i++)
        {
            if (isalnum(s[i]))
            {
                t+=tolower(s[i]);
                // t+=s[i];
                // j++;
            }
                
        }

        int left = 0;
        int right = t.size()-1;

        cout << t;
        while (left<=right)
        {
            if (t[left]!=t[right])
                return false;
            
            left++;
            right--;
        }

        return true;

    }
};