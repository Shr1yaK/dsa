class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int n = s.size();
        //cout << n;

        int left = 0;
        int right = n-1;

        while (left<=right)
        {
            char temp = s[right];
            s[right]=s[left];
            s[left]=temp;
            left++;
            right--;
        }
    }
};