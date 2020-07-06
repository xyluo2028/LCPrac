// LCPrac35.cpp : This file contains the 'main' function. Program execution begins and ends there.
// buildings [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ]
// solution [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool comp(vector<int>& A, vector<int>& B) {
    if (A[0] < B[0]) return true;
    else return false;
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        result = make_slice(buildings);
        make_peaks(result);
        return result;
    }

private:
    vector<vector<int>> make_slice(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        vector<int> tmp(2);
        for (int i = 0; i < buildings.size(); i++)
        {
            for (int j = buildings[i][0]; j < buildings[i][1]; j++)
            {
                tmp[0] = j;
                tmp[1] = buildings[i][2];
                result.push_back(tmp);
            }
        }
        sort(result.begin(),result.end(), comp);
        return result;
    }

    void make_peaks(vector<vector<int>>& slices) {
        vector<int> tmp(2);
        tmp[0] = slices.back()[0]+1;
        tmp[1] = 0;
        slices.push_back(tmp);
        tmp[0]++;
        slices.push_back(tmp);
        int len = slices.size();
        priority_queue<int> pq;
        pq.push(slices[0][1]);
        int pos = slices[0][0];
        for (int i = 1; i < len; i++)
        {
            while (slices[i][0] > pos) {
                tmp[0] = pos;
                tmp[1] = pq.top();
                slices.push_back(tmp);
                while (!pq.empty()) pq.pop();
                if (slices[i][0] > pos +1) pq.push(0);
                else pq.push(slices[i][1]);
                pos++;
            }
            pq.push(slices[i][1]);
        }
        slices.erase(slices.begin(), slices.begin() + len);
    }
};

int main()
{
    Solution solve;
    vector<vector<int>> test{ {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
    vector<vector<int>> result = solve.getSkyline(test);
    for (auto item : result) {
        cout << item[0] << ", " << item[1] << endl;
    }
}

