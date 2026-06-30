class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector <int> ans(n+1,0);
        for (int i = 0; i<=n; i++)
        {
            // int count = 0;
            // int num = i;
            // while (num)
            // {
            //     if (num & 1)    count++;
            //     num = num >> 1;
            // }
            // ans[i]=count;
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};