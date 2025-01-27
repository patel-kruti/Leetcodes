// Problem : 355. Design Twitter
// Link: https://leetcode.com/problems/design-twitter/
// Topics: Hash Table, Heap, Design, Priority_Queue
// Time and Space Complexity: 
// Post a Tweet:
// Time: O(1) to add the tweet to the list.
// Space: O(1) for each tweet.

// Get News Feed:
// Time: O(F+TlogT), where F is the number of followees, and T is the total number of tweets considered (user's tweets + followees' tweets).
// Space: O(T) for the priority queue.

// Follow and Unfollow:
// Time: O(1) for insertions or deletions in the unordered_set.
// Space: O(1) for each follow/unfollow relationship.

// Solution 1: Using Hash Map and Priority Queue
class Twitter {
private:
    int timestamp;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
    std::unordered_map<int, std::unordered_set<int>> following;
public:
    Twitter() : timestamp(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::pair<int, int>> pq;
        for(auto&tweet: tweets[userId]){
            pq.push(tweet);
        }

        for(int followeeId: following[userId]){
            for(auto&tweet: tweets[followeeId]){
                pq.push(tweet);
            }
        }

        std::vector<int> feed;
        for(int i = 0; i < 10 && !pq.empty(); i++){
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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