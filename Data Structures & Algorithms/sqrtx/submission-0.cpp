class Solution {
public:
    int mySqrt(int x) {
        if (x==0)
            return 0;

        if (x==1)
            return 1;

        int start = 1;
        int end = x;
        while (start<=end)
        {
            int mid = start + (end - start)/2;
            long long sq = 1LL * mid * mid;

            if (sq==x)
                return mid;

            if (sq>x)
                end = mid-1;
            
            else
                start = mid+1;
        }

        return end;
    }
};