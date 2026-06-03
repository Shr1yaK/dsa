class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map <int, int> mp;
        for (int num : nums)
        {
            mp[num]++;
        }

        vector<pair<int, int>> freq(mp.begin(), mp.end());
        sort(freq.begin(), freq.end(), 
            [](pair<int, int> &o1, pair<int, int> &o2) 
            {
                return o1.second > o2.second;
            });

        vector<int> result;
        for (int i = 0; i<k; i++)
            result.push_back(freq[i].first);
        return result;
    }
};