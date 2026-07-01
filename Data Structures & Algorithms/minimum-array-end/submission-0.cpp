class Solution {
public:
    long long minEnd(int n, int x) 
    {
        long long k = n - 1;
        long long ans = x;

        int pos = 0;
        while (k > 0)
        {
            if (((ans >> pos) & 1) == 0)
            {
                if (k & 1)
                    ans |= (1LL << pos);

                k >>= 1;
            }
            pos++;
        }
        return ans;
    }
};