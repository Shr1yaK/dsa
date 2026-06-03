class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector <int> answer (2);
        int left = 0; 
        int right = numbers.size()-1;

        while (left<=right)
        {
            int sum = numbers[left]+numbers[right];
            if (sum==target)
            {
                answer[0]=left+1;
                answer[1]=right+1;
                return answer;
            }

            if (sum>target) 
                right--;

            if (sum<target)
                left++;
        }

        return answer;
    }
};