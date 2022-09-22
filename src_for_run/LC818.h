/*
Input: target = 6
Output: 5
Explanation: 
The shortest instruction sequence is "AAARA".
Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.
*/

#include "common.h"

class Solution818BFS {
public:
    int racecar(int target) {
        // 1. Initialize double ended queue as 0 moves, 0 position, +1 velocity
        queue<vector<int>> q;
        q.push({0, 0, 1});
        while (!q.empty()) {
            
            vector<int> item = q.front();
            q.pop();
            
            // (moves) moves, (pos) position, (vel) velocity)
            int moves = item[0];
            int pos = item[1];
            int vel = item[2];
            
            if (pos == target) return moves;
            
            // Avoid integer overflow - stop whenever we've passed twice the magnitude of target.
            if (abs(pos) > 2 * target) continue;
            
            // 2. Always consider moving the car in the direction it is already going
            q.push({moves + 1, pos + vel, 2 * vel});
            
            // 3. Only consider changing the direction of the car if one of the following conditions is true
            //    i.  The car is driving away from the target.
            //    ii. The car will pass the target in the next move.  
            if ((pos + vel > target && vel > 0) || (pos + vel < target && vel < 0)) {
                q.push({moves + 1, pos, (vel > 0) ? -1 : 1});
            }
         }
         return 0;
     }

};


class Solution818DP {
public:
    int racecar(int target) {
        int power = floor(log2(target));
        int lowb = (1 << power) - 1;
        int highb = (1 << (power + 1)) - 1;
        if (target == lowb) return power;
        if (target == highb) return power + 1;
        //cout << power << endl;
        //cout << lowb << " : " << highb << endl;
        vector<int> dp(highb + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= power + 1; ++i) {
            dp[accl(i)] = i;
        }
        for (int dist = 1; dist <= target; ++dist) {
            //cout << "dist = " << dist << endl;
            if (dp[dist] <= 0) {
                int upper = find_upper(dist) - 1;
                //cout << upper << endl;
                int lower = (upper + 1) / 2 - 1;
                
                int tmp_lowP = log2(lower + 1);
                
                int possible1 = dp[upper] + 1 + dp[upper - dist];  // pass the targat and go back
                for (int m = 0; m <= tmp_lowP - 1; ++m) {   // doesn't pass the target, go back, move m steps, go back to target
                    int possible2 = dp[lower] + 1 + m + 1 + dp[dist - (lower - (1 << m) + 1)];
                    possible1 = possible2 < possible1 ? possible2 : possible1;
                }
                dp[dist] = possible1;
            }
            //cout << "dp[dist] = " << dp[dist] << endl;
        }
        
        return dp[target];
    }
    
    int accl(int n) {
        return (1 << n) - 1;
    }
    
    int find_upper(int n) {
        int power = floor(log2(n)) + 1;
        return 1 << power;
    }
};