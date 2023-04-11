//Number of Submatrices That Sum to Target
#include "common.h"
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        int w = matrix[0].size();
        vector<vector<int>> memo(h, vector<int>(w, 0));
        memo[0][0] = matrix[0][0];
        for (int i = 1; i < h; ++i) {
            memo[i][0] = memo[i-1][0] + matrix[i][0];
        }
        for (int i = 1; i < w; ++i) {
            memo[0][i] = memo[0][i-1] + matrix[0][i];
        }
        for (int i = 1; i < h; ++i) {
            for (int j = 1; j < w; ++j) {
                memo[i][j] = memo[i-1][j] + memo[i][j-1] - memo[i-1][j-1] + matrix[i][j];
            }
        }
        int ans = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < w; ++i) {
            for (int j = i; j < w; ++j) {
                umap.clear();
                umap[0] = 1;
                for (int k = 0; k < h; ++k) {
                    int cur_sum = 0;
                    if (i == 0) {
                        cur_sum = memo[k][j];
                    } else {
                        cur_sum = memo[k][j] - memo[k][i-1];
                    }
                    ans += umap[cur_sum - target];
                    umap[cur_sum]++;
                }
            }
        }
        return ans;
    }
};