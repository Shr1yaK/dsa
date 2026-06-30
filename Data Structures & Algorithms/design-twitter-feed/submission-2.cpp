class Twitter {
public:
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int timestamp = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) 
    {
        tweets[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        priority_queue<pair<int,int>> pq;
        for (auto tweet : tweets[userId])
            pq.push(tweet);
        
        for (int followee : follows[userId])
        {
            for (auto tweet : tweets[followee])
                pq.push(tweet);
        }

        vector<int> feed;
        while (!pq.empty() && feed.size() < 10)
        {
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) 
    {
        if (followerId != followeeId)
            follows[followerId].insert(followeeId);    
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        follows[followerId].erase(followeeId);    
    }
};
