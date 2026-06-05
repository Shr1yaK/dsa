class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int left = 0;
        int right = arr.size()-1;
        // unordered_map <int,int> dist;
        // for (int i = 0; i<arr.size(); i++)
        // {
        //     dist[i]=abs(arr[i]-x);
        // }
        while(right-left+1!=k)
        {
            if ((abs(arr[left]-x)<abs(arr[right]-x)) || (abs(arr[left]-x)==abs(arr[right]-x) && arr[left]<arr[right]))
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        vector<int>answer;
        for (int j = left;j<right+1;j++)
        {
            answer.push_back(arr[j]);
        }

        return answer;

        //valid window only when right-left+1=k
    }
};