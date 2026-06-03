class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int k = 0;
        int slow = 0;
        int fast = 0;

        while (fast<nums.size())
        {
            if (nums[slow]!=nums[fast])
            {
                slow++;
                nums[slow]=nums[fast];
            }

            fast++;
        }
        k=slow+1;
        return k;   
    }
};