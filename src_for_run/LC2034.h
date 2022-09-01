#include "common.h"

struct MyCompGreater {
public:
    MyCompGreater() {}
        
    bool operator() (const pair<int, int> a, const pair<int, int> b) {
        return a.second > b.second;
    }
};

struct MyCompLess {
public:
    MyCompLess() {}
        
    bool operator() (const pair<int, int> a, const pair<int, int> b) {
        return a.second < b.second;
    }
};

class StockPrice {
public:
    
    StockPrice() {}
    
    void update(int timestamp, int price) {
        if (timestamp > curr) curr = timestamp;
        maxPQ.push({timestamp, price});
        minPQ.push({timestamp, price});
        timeToPrice[timestamp] = price;
        
    }
    
    int current() {
        if (!timeToPrice[curr]) return -1;
        return timeToPrice[curr];
    }
    
    int maximum() {
        while (true) {
            auto temp = maxPQ.top();
            if (timeToPrice[temp.first] == temp.second) {
                return temp.second;
            }
            maxPQ.pop();
        }
    }
    
    int minimum() {
        while (true) {
            auto temp = minPQ.top();
            if (timeToPrice[temp.first] == temp.second) {
                return temp.second;
            }
            minPQ.pop();
        }
    }
    
private:
    unordered_map<int, int> timeToPrice;
    int curr = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompGreater> minPQ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompLess> maxPQ;
    
};