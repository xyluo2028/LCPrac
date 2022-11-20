// Longest Common Subsequence
/*
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
*/
#include "common.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n2 + 1, vector<int>(n1 + 1, 0));
        for (int i = 1; i <= n2; ++i) {
            for (int j = 1; j <= n1; ++j) {
                if (text1[j-1] == text2[i-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n2][n1];
        
    }
};