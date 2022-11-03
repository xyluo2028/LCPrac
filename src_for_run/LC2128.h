#include "common.h"

class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int tmp = grid[0][i];
            for (int j = 0; j < m; ++j) {
                if (tmp != grid[j][i]) return false;
            }
        }
        return true;
    }
};