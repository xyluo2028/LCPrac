#include <iostream>
#include <vector>

#define INTMAX 2147483647

using namespace std;


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

    }

private:
    vector<vector<int>> getSubSol(vector<vector<int>>& buildings, int left, int right) {
        vector<vector<int>> result;
        vector<vector<int>> result1;
        int mid;
        if (left == right) {
            result = singleBuildingSkyline(buildings[left]);
            return result;
        }
        else {
            mid = (left + right) * 0.5;
            result = getSubSol(buildings, left, mid);
            result1 = getSubSol(buildings, mid + 1, right);
            mergeSkyline(result, result1);
            return result;
        }
    }

    void mergeSkyline(vector<vector<int>>& Lskyline, vector<vector<int>>& Rskyline) {

    }

    vector<vector<int>> singleBuildingSkyline(vector<int> building) {

    }
};