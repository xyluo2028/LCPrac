// LCPrac35.cpp : This file contains the 'main' function. Program execution begins and ends there.
// buildings {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}
// {1, 3, 3}, {2, 4, 5}, {3, 5, 4}, {6, 8, 3}, {7, 9, 4}
// {2147483646, 2147483647, 2147483647}
//[[1,2,1],[2147483646,2147483647,2147483647]]
// solution [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INTMAX 2147483647

using namespace std;



bool comp(vector<int>& A, vector<int>& B) {
    if (A[0] < B[0]) return true;
    else return false;
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        if (buildings.empty()) return result;
        result = make_slice(buildings);
        if (buildings.size() == 1) return result;
        make_peaks(result);
        for (auto item : result) {
            cout << item[0] << ", " << item[1] << endl;
        }
        int iter = 1;
        int prev = result[0][0];
        int conti = 0;
        vector<int> tmp(2);
        while (iter < result.size())
        {
            cout << result[iter][0] << "  #  " << result[iter - 1][0] << endl;
            if (result[iter][1] == result[iter - 1][1] && result[iter][0] == result[iter - 1][0]+1 && conti==0) {  //高度相同，x轴连续, 上一帧不连续
                prev = iter;
                conti++;
            }
            else if (result[iter][1] == result[iter - 1][1] && result[iter][0] == result[iter - 1][0]+1 && conti > 0) {//  高度相同，x轴连续, 上一帧连续
                conti++;
            }
            else if (result[iter][1] != result[iter - 1][1] && result[iter][0] == result[iter - 1][0]+1 && conti > 0) { // x连续，上一帧连续，高度出现变化
                result.erase(result.begin() + prev, result.begin() + prev + conti);
                iter=iter-conti;
                conti = 0;
            }
            else if (result[iter][0] > result[iter-1][0]+1 && conti > 0) { // x轴出现断点，需要补0，上一帧连续
                cout << "breakP conti" << endl;
                tmp[0] = result[iter - 1][0]+1;
                tmp[1] = 0;
                result.insert(result.begin() + iter , tmp);
                result.erase(result.begin() + prev, result.begin() + prev + conti);
                iter = iter - conti + 1;
                conti = 0;
            }
            else if (result[iter][0] > result[iter - 1][0] + 1 && conti == 0) {// x轴出现断点，需要补0，上一帧不连续
                cout << "breakP no-conti" << endl;
                tmp[0] = result[iter-1][0]+1;
                tmp[1] = 0;
                result.insert(result.begin() + iter, tmp);
                iter++;
            }
            iter++;
        }
        
        return result;
    }

private:
    vector<vector<int>> make_slice(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        vector<int> tmp(2);
        if (buildings.size() == 1) {
            tmp[0] = buildings[0][0];
            tmp[1] = buildings[0][2];
            result.push_back(tmp);
            tmp[0] = buildings[0][1];
            tmp[1] = 0;
            result.push_back(tmp);
            return result;
        }
        for (int i = 0; i < buildings.size(); i++)
        {
            if (buildings[i][1] > INTMAX || buildings[i][2] > INTMAX) break;
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
        //tmp[0]++;
        //slices.push_back(tmp);
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
                pos = slices[i][0];
            }
            pq.push(slices[i][1]);
        }
        slices.erase(slices.begin(), slices.begin() + len);
        tmp[0] = slices.back()[0] + 1;
        tmp[1] = 0;
        slices.push_back(tmp);
    }
};

int main()
{
    cout << INTMAX << endl;
    Solution solve;
    vector<vector<int>> test{ {1,2,1}, {2147483646,2147483647,2147483647} };
    vector<vector<int>> result = solve.getSkyline(test);
    for (auto item : result) {
        cout << item[0] << ", " << item[1] << endl;
    }
}
