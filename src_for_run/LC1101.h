/*
union find
Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
Output: 20190301
*/

#include "common.h"

class Solution {
public:
    vector<int> parents;
    int find_p(int p) {
        return parents[p] == p ? p : find_p(parents[p]);
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        parents.resize(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        int rank = n;
        int N = logs.size();
        for (int i = 0; i < N; ++i) {
            int p1 = find_p(logs[i][1]);
            int p2 = find_p(logs[i][2]);
            if (p1 != p2) {
                --rank;
                if (rank == 1)return logs[i][0];
                else {
                    parents[p2] = p1;
                }
            }
        }
        return -1;
    }
};