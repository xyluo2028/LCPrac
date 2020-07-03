// LCPrac32.cpp : This file contains the 'main' function. Program execution begins and ends there.
//[1,4,1,1,2,3,2,1]

#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        if (arr.empty()) return 0;
        int len = arr.size();
        if (len == 1) return 1;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int tmp = 0;
        int tmp1 = 0;
        for (size_t i = 0; i < len; i++)
        {
            dp[i][i] = 1;
        }
        for (size_t i = 1; i < len; i++)
        {
            for (size_t j = 0; j < len-i; j++)
            {
                if (i == 1) {
                    dp[j][j + i] = (arr[j] == arr[j + i]) ? 1 : 2;
                }
                else {
                    tmp = minsum(dp, j, j + i);
                    tmp1 = (arr[j] == arr[j + i]) ? dp[j + 1][j + i - 1] : tmp;
                    dp[j][j + i] = (tmp1<tmp) ? tmp1 : tmp;
                }
            }
        }
        return dp[0][len - 1];
    }
private:
    int minsum(vector<vector<int>>& dp, size_t x, size_t y) {
        int result = dp[x][x] + dp[x+1][y];
        for (size_t i = 1; i < y-x; i++)
        {
            if (result > dp[x][x + i] + dp[x + 1 + i][y]) result = dp[x][x + i] + dp[x + 1 + i][y];
        }
        return result;
    }
};


int main()
{
    Solution solve;
    vector<int> arr = { 1,3,1,1,5,4,1 };
    int result = solve.minimumMoves(arr);
    cout << result << endl;
}

