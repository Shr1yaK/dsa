class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int i = 0; i<weights.size(); i++)
        {
            high+=weights[i];
        }

        while (low<=high)
        {
            int mid = low + (high-low)/2;
            int sum = 0;
            int count = 1;
            for (int i = 0; i<weights.size(); i++)
            {
                if (sum+weights[i]<=mid)
                {
                    sum=sum+weights[i];
                }
                else
                {
                    count++;
                    sum=0+weights[i];

                }
            }

            if (count <= days)  high = mid-1;
            else    low = mid+1;
        }
        return low;
    }
};