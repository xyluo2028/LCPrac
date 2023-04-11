//Edit Distance
/*
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
*/
#include "common.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int tmp = word1[i-1] == word2[j-1] ? dp[i-1][j-1]-1 : dp[i-1][j-1];
                dp[i][j] = 1 + minOfThree(dp[i-1][j], dp[i][j-1], tmp);
            }
        }
        return dp[m][n];
    }
    
    int minOfThree(int a, int b, int c) {
        return min(a, min(b,c));
    }
};