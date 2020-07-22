#include <iostream>
#include <vector>

#define INTMAX 2147483647

using namespace std;


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        if (buildings.empty()) return result;
        result = getSubSol(buildings, 0, buildings.size() - 1);
        return result;
    }

private:
    vector<vector<int>> getSubSol(vector<vector<int>>& buildings, int left, int right) {
        vector<vector<int>> resultLeft;
        vector<vector<int>> resultRight;
        vector<vector<int>> resultMerge;
        int mid;
        if (left == right) {
            singleBuildingSkyline(buildings[left], resultMerge);
            return resultMerge;
        }
        else {
            mid = (left + right) * 0.5;
            resultLeft = getSubSol(buildings, left, mid);
            resultRight = getSubSol(buildings, mid + 1, right);
            mergeSkyline(resultLeft, resultRight, resultMerge);
            return resultMerge;
        }
    }

    void mergeSkyline(vector<vector<int>>& Lskyline, vector<vector<int>>& Rskyline, vector<vector<int>>& result) {
        if (Lskyline.back()[0] < Rskyline[0][0]) {
            for (auto item:Lskyline)
            {
                result.push_back(item);
            }
            for (auto item : Rskyline) {
                result.push_back(item);
            }
            return;
        }
        int L_node = 0;
        int R_node = 0;
        int R_x;
        int L_x;
        int R_h = 0;
        int L_h = 0;
        vector<int> tmp(2);
        
        while (R_node<Rskyline.size()||L_node<Lskyline.size())
        {
            if (R_node < Rskyline.size()) {
                R_x = Rskyline[R_node][0];
            }
            else {
                R_x = INTMAX;
                R_h = -1;
            }
            if (L_node < Lskyline.size()) {
                L_x = Lskyline[L_node][0];
            }
            else {
                L_x = INTMAX;
                L_h = -1;
            }
            
            if (L_x == R_x) {       //左右地平线当前拐点x轴坐标重合
                tmp[0] = L_x;
                L_h = Lskyline[L_node][1];
                R_h = Rskyline[R_node][1];
                if (L_h> R_h)
                {
                    tmp[1] = L_h;
                }
                else {
                    tmp[1] = R_h;
                }
                L_node++;
                R_node++;
                if (result.empty() || tmp[1]!=result.back()[1])result.push_back(tmp);
            }
            else if (L_x < R_x) {   //左地平线遇到拐点
                L_h = Lskyline[L_node][1];
                if(L_h > R_h || R_node==0) {
                    tmp[0] = L_x;
                    tmp[1] = L_h;
                    result.push_back(tmp);
                }
                else if (L_h<R_h && R_h< result.back()[1]) {
                    tmp[0] = L_x;
                    tmp[1] = R_h;
                    result.push_back(tmp);
                }
                L_node++;
            }
            else {                  //右地平线遇到拐点
                R_h = Rskyline[R_node][1];
                if (R_h > L_h) {
                    tmp[0] = R_x;
                    tmp[1] = R_h;
                    result.push_back(tmp);
                }
                else if (L_h > R_h && L_h < result.back()[1]) {
                    tmp[0] = R_x;
                    tmp[1] = L_h;
                    result.push_back(tmp);
                }
                R_node++;
            }
        }
    }

    void singleBuildingSkyline(vector<int>& building, vector<vector<int>>& result) {
        vector<int> tmp(2);
        tmp[0] = building[0];
        tmp[1] = building[2];
        result.push_back(tmp);
        tmp[0] = building[1];
        tmp[1] = 0;
        result.push_back(tmp);
    }
};
