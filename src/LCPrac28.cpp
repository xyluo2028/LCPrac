// LCPrac37.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  [[1,4],[4,4],[2,2],[3,4],[1,1]]

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <unordered_set>

using namespace std;


const int MAX = 1e5 + 1;

bool comp(vector<int>& a, vector<int>& b) {
    if (a[1] < b[1]) return true;
    
    else return false;
}



class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if (events.empty()) return 0;
        vector<vector<int>> days(MAX);
        for (int i = 0; i < events.size(); i++)
        {
            days[events[i][0]].push_back(i);
        }
        int result = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i < MAX; i++)
        {
            for (auto evt:days[i])
            {
                cout << evt << endl;
                pq.push(events[evt][1]);
            }
            while (!pq.empty()&&pq.top()<i)
            {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                result++;
            }
        }        
        return result;
    }

};


int main()
{
    Solution solve;
    vector<vector<int>> test = { { 1,3 }, { 1,3 }, { 1,3 }, { 3,4}};
    int result = solve.maxEvents(test);
    cout << result << endl;
}
