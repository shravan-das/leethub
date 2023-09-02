class Twitter {
public:
    map<int,set<int>>mp;
    priority_queue<vector<int>>timeline;
    int curr = 0;
    Twitter() {
      mp.clear();
      curr = 0;
        
    }
    
    void postTweet(int userId, int tweetId) {
      curr = curr+1;
      timeline.push({curr,tweetId,userId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
      vector<int>ans;
      int count = 0;
      priority_queue<vector<int>>pq = timeline;
      while(!pq.empty() && count<10){
        vector<int>it = pq.top();
        pq.pop();
        int tid = it[1];
        if(it[2]==userId or mp[userId].find(it[2])!=mp[userId].end()){
          ans.push_back(tid);
          count++;
        }
      }
      
      return ans;
        
    }
    
    void follow(int followerId, int followeeId){
      mp[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
      mp[followerId].erase(followeeId);
        
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