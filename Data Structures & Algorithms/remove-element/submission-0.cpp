class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size()-1;
        while (i<=j)
        {
            if (nums[i]==val)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j--;
            }
            else
            {
                i++;
            }
        }
        return j+1;

        }
    };