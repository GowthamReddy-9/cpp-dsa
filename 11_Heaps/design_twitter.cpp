#include <bits/stdc++.h>
using namespace std;

class Twitter {
    struct Tweet{
        int id;
        int time;
        Tweet(int id,int time):id(id),time(time){}
    };
    struct cmp{
        bool operator()(const Tweet* a,const Tweet* b){
            return a->time>b->time;
        }
    };
    unordered_map<int,vector<Tweet>> tweets;
    unordered_map<int,unordered_set<int>> following;
    int time;
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId,time++);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet*,vector<Tweet*>,cmp> pq;
        for(auto& tweet:tweets[userId]){
            pq.push(&tweet);
            if(pq.size()>10) pq.pop();
        }
        for(auto user:following[userId]){
            for(auto& tweet:tweets[user]){
                pq.push(&tweet);
                if(pq.size()>10) pq.pop();
            }
        }
        vector<int> feed;
        feed.reserve(pq.size());
        while(!pq.empty()){
            feed.push_back(pq.top()->id);
            pq.pop();
        }
        int l=0;  int r=feed.size()-1;
        while(l<r){
            swap(feed[l],feed[r]);
            l++;
            r--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId) following[followerId].insert(followeeId);
        else cout<<"User can't follow himself"<<endl;
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
    
    void printNewsFeed(int userId) {
        vector<int> feed = getNewsFeed(userId);
        cout << "News feed for user " << userId << ": ";
        for (int tweetId : feed) {
            cout << tweetId << " ";
        }
        cout << endl;
    }
};

int main() {
    Twitter* twitter = new Twitter();
    
    cout << "Test 1: Basic posting" << endl;
    twitter->postTweet(1, 5);
    twitter->postTweet(2, 3);
    twitter->printNewsFeed(1);
    twitter->printNewsFeed(2);
    cout << endl;
    
    cout << "Test 2: Follow and news feed" << endl;
    twitter->follow(1, 2);
    twitter->printNewsFeed(1);
    twitter->printNewsFeed(2);
    cout << endl;
    
    cout << "Test 3: More posts and unfollow" << endl;
    twitter->postTweet(1, 6);
    twitter->postTweet(2, 4);
    twitter->printNewsFeed(1);
    twitter->unfollow(1, 2);
    twitter->printNewsFeed(1);
    cout << endl;
    
    cout << "Test 4: 10+ tweets limit" << endl;
    for(int i = 10; i < 25; i++) {
        twitter->postTweet(3, i);
    }
    twitter->printNewsFeed(3);
    
    delete twitter;
    return 0;
}