// two pointer
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int maxarea = -1;
        int area = -1;

        int left = 0;
        int right = height.size()-1;

        while (left<right)
        {
            area = (right-left) * min(height[left], height[right]);
            maxarea = max(area, maxarea);

            if (height[left]<height[right])
                left++;
            
            else
                right--;
        }

        return maxarea;
    }
};