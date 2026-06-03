class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int look = 0-nums[i];
            int left = i+1;
            int right = nums.size()-1;

            while(left<right)
            {
                int sum = nums[left]+nums[right];

                if (sum < look)
                    left++;
                
                else if (sum > look)
                    right--;
                
                else
                {
                    
                    // vector<int>entry;
                    // entry.push_back(nums[left]);
                    // entry.push_back(nums[i]);
                    // entry.push_back(nums[right]);
                    
                    answer.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while(left<right && nums[left]==nums[left-1])
                        left++;

                    while(left<right && nums[right]==nums[right+1])
                        right--;
                }
            }
        }
        return answer;
    }
};