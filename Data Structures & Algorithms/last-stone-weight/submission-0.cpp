class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
       priority_queue<int> pq;
       for (int stone : stones)
       {
            pq.push(stone);
       }

       while (pq.size()>1)
       {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (y>x or x>y)
                pq.push(abs(x-y));
       }

       if (pq.empty())
            return 0;
       else
            return pq.top();
    }
};