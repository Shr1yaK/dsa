class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        int left = 0;
        unordered_set<int> window;
        for (int right = 0; right<nums.size(); right++)
        {
            if (window.count(nums[right]))
                return true;

            window.insert(nums[right]);

            if (window.size() > k)
            {
                window.erase(nums[left]);
                    left++;
            }
        }
        return false;
    }
};