#include "common.h"

class Solution {
public:
    int maximumRobots(vector<int>& times, vector<int>& costs, long long budget) {
        long long i = 0, j = 0;
        multiset<int> ms;
        for (long long cost = 0; i < times.size(); ++i) {
            cost += costs[i];
            ms.insert(times[i]);
            if (cost * (i - j + 1) + *ms.rbegin() > budget) {
                cost -= costs[j];
                ms.erase(ms.find(times[j]));
                ++j;
            }
        }
        return i - j;
    }
};