#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int tmp;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (size_t i = 1; i < m; i++)dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (size_t j = 1; j < n; j++)dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                tmp = dp[i][j - 1] > dp[i - 1][j] ? dp[i - 1][j] : dp[i][j - 1];
                dp[i][j] = tmp + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution solve;
    vector<vector<int>> test = { {1,3,1}, {1,5,1}, {4,2,1} };
    int result = solve.minPathSum(test);
    cout << result << endl;
}
