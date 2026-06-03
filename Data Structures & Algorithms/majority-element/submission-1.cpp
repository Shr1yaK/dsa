// hashing
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map <int, int> freq;
        int max = n/2;
        for (int num: nums)
        {
            freq[num]++;

            if (max < freq[num])
                return num;
        }
        return -1;
    }
};