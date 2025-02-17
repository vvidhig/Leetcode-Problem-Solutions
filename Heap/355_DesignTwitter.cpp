class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> userTweet;
    unordered_map<int, unordered_set<int>> follower;
    int timestamp;
public:
    Twitter() 
    {
        timestamp=0;
    }
    void postTweet(int userId, int tweetId) 
    {
        userTweet[userId].push_back({tweetId, timestamp++});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for(auto &x:userTweet[userId])
        {
            pq.push({x.second, x.first});
        }

        for(auto &x:follower[userId])
        {
            for(auto y:userTweet[x])
            {
                pq.push({y.second, y.first});
            }
        }
        int count = 0;
        while(!pq.empty() && count<10)
        {
            res.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) 
    {
        if(followerId != followeeId)
            follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
