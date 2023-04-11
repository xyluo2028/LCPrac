// Minimum Interval to Include Each Query
#include "common.h"
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        auto comp = [](vector<int>& v1, vector<int>& v2) {
            return v1[1] - v1[0] < v2[1] - v2[0];
        };
        sort(intervals.begin(), intervals.end(), comp);
        int ni = intervals.size();
        int nq = queries.size();
        vector<int> ans(nq, -1);
        set<pair<int, int>> sset;
        for (int i = 0; i < nq; ++i) {
            sset.emplace(queries[i], i);
        }
        for (auto& itv: intervals) {
            auto it = sset.lower_bound({itv[0], 0});
            while (it != sset.end() && itv[1] >= it->first) {
                ans[it->second] = itv[1] - itv[0] + 1;
                sset.erase(it++);
            }
        }
        return ans;
    }
};