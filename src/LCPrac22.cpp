// LCPrac28.cpp : This file contains the 'main' function. Program execution begins and ends there.
// [[0,30],[5,10],[15,20]]

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) return true;
        int len = intervals.size();
        //bool result = true;
        //_sort(intervals, len, result);
        //return result;
        for (size_t i = 0; i < len-1; i++)
        {
            for (size_t j = i+1; j < len; j++)
            {
                if (overlap(intervals[i], intervals[j])) return false;
            }
        }
        return true;
    }

private:
    void _sort(vector<vector<int>>& intervals, int len, bool& result) {
        vector<int> tmp;
        for (size_t i = 0; i < len; i++)
        {
            for (size_t j = 1; j < len - i; j++) {
                if (intervals[j - 1][0] > intervals[j][0]) {
                    tmp = intervals[j];
                    intervals[j] = intervals[j - 1];
                    intervals[j - 1] = tmp;
                }
            }
            if (i>0 && intervals[len-i][0] < intervals[len-i-1][1]){
                result = false;
                return;
            }
        }
    }

    bool overlap(vector<int> x1, vector<int> x2) {
        if (x1[0] >= x2[0] && x1[0] < x2[1] || x2[0] >= x1[0] && x2[0] < x1[1]) return true;
        return false;
    }
};

int main()
{
    Solution solve;
    vector<vector<int>> test = { {0,30}, {5, 10}, {15,20} };
    bool result = solve.canAttendMeetings(test);
    cout << result << endl;
}

