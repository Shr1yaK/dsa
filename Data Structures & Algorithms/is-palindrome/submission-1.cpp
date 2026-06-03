class Solution {
public:
    bool isPalindrome(string s) 
    {
        //int n = s.size();
        // cout <<n;
        
        //string t;
        // int j = 0;
        // for (int i = 0; i<n; i++)
        // {
        //     if (isalnum(s[i]))
        //     {
        //         t+=tolower(s[i]);
        //         // t+=s[i];
        //         // j++;
        //     }
                
        // }

        int left = 0;
        int right = s.size()-1;

        //cout << t;
        while (left<right)
        {
            if (isalnum(s[left]) == false)
                left++;
            
            else if (isalnum(s[right]) == false)
                right--;
            
            else
            {
                if (tolower(s[left]) != tolower(s[right]))
                    return false;

                left++;
                right--;
            }
        }

        return true;

    }
};