class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int ans = 0;

    // XOR every integer from 0 to n
    for (int i = 0; i<=nums.size(); i++)
        ans = ans ^ i;

    // XOR every element in nums
    for (int num : nums)
        ans = ans ^ num;

    return ans;

    }
};