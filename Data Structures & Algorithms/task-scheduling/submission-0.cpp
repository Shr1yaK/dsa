class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        priority_queue <int> pq;
        queue<pair<int,int>> cooldown; //{remaining freq, next time}

        vector<int> freq_arr(26,0);
        for (char task : tasks)
            freq_arr[task-'A']++;

        for(int freq : freq_arr)
        {
            if(freq > 0)
                pq.push(freq);
        }

        int time = 0;
        while (!pq.empty() || !cooldown.empty())
        {
            time++;

            if(!cooldown.empty() && cooldown.front().second == time)
            {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!pq.empty())
            {
                int freq = pq.top();
                pq.pop();

                freq--;

                if(freq > 0)
                    cooldown.push({freq, time + n + 1});
            }
        }
        
        return time;
    }
};