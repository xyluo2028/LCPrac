#include "common.h"

class Solution48 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size() - 1;
        int tmp = 0;
        while(left < right) {
            for (int i = left; i < right; ++i) {
                tmp = matrix[left][i];
                matrix[left][i] = matrix[right - i + left][left];
                matrix[right - i + left][left] = matrix[right][right - i + left];
                matrix[right][right - i + left] = matrix[i][right];
                matrix[i][right] = tmp;
            }
            ++left;
            --right;
        }
    }
};