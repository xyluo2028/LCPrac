/*
You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0.
At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1])
which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are 
no more elements in the array.

Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, 
and you should also return true. You may assume that both players are playing optimally.
*/


#include "common.h"

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, {vector<int>(n,0)});
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (i == j) {
                    dp[j][i] = nums[i];
                } else {
                    int res1 = nums[j] - dp[j+1][i];
                    int res2 = nums[i] - dp[j][i-1];
                    dp[j][i] = max(res1, res2);
                }
            }
        }
        return dp[0][n-1] >= 0;
        
    }
};