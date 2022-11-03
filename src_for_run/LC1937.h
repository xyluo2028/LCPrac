/*
Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
*/

#include "common.h"

class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        vector<long long> cur_row(p[0].size()), prev_row(p[0].size());
        for (auto &row : p) {
            for (long long j = 0, run_max = 0; j < row.size(); ++j) {
                run_max = max(run_max - 1, prev_row[j]);
                cur_row[j] = run_max;
            }
            for (long long j = row.size() - 1, run_max = 0; j >= 0; --j) {
                run_max = max(run_max - 1, prev_row[j]);
                cur_row[j] = max(cur_row[j], run_max) + row[j];
            }
            swap(cur_row, prev_row);
        }
        return *max_element(begin(prev_row), end(prev_row));
    }
};