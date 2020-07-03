// LCPrac21.cpp : This file contains the 'main' function. Program execution begins and ends there.
// DP

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return 1;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for (size_t i = 2; i < n+1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        
    }
};

int main()
{
    Solution solve;
    int test = 44;
    int result = solve.climbStairs(test);
    cout << result << endl;
}
