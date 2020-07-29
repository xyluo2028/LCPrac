// LCPrac28.cpp : This file contains the 'main' function. Program execution begins and ends there.
//[[7,10],[2,4]]/{2,15}, {36,45}, {9,29},{16,23},{4,9}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> tmp;
        int result = 0;
        while (!intervals.empty()) {
            for (int i = 0; i < intervals.size() - 1; i++) {
                cout << intervals[i][0] <<","<< intervals[i][1]<< endl;
                if (overlap(intervals[i], intervals[i + 1])) {
                    //if (intervals[i + 1][1]-intervals[i+1][0] > intervals[i][1]-intervals[i][0]) {
                    //    tmp.push_back(intervals[i + 1]);
                    //    intervals.erase(intervals.begin() + i+1);
                    //}
                    //else {
                    //    tmp.push_back(intervals[i]);
                    //    intervals.erase(intervals.begin() + i);
                    //}
                    tmp.push_back(intervals[i+1]);
                    intervals.erase(intervals.begin() + i+1);
                    i--;
                }
            }
            result++;
            intervals.clear();
            intervals = tmp;
            tmp.clear();
        }
        return result;
    }

private:
    bool overlap(vector<int> a, vector<int> b) {
        if (a[0] >= b[0] && a[0] < b[1] || b[0] >= a[0] && b[0] < a[1]) return true;
        return false;
    }
};

int main()
{
    Solution solve;
    vector<vector<int>> test = { {9,29},{9,23},{23,26} };
    int result = solve.minMeetingRooms(test);
    cout << result << endl;
}


