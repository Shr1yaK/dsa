// brute force
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int max = -1;
        int area = -1;
        for (int i = 0; i<height.size(); i++)
        {
            for (int j = i+1; j<height.size(); j++)
            {
                if (height[i] < height[j])
                    area = (j-i) * height[i];
                
                else
                    area = (j-i) * height[j];

                if (max<area)
                    max = area;
            }
        }
        return max;
    }
};