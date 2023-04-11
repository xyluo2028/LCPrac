//Minimum Cost to Reach City With Discounts
#include "common.h"

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& vec : highways) {
            graph[vec[0]].push_back({vec[1], vec[2]});
            graph[vec[1]].push_back({vec[0], vec[2]});
        }
        vector<vector<int>> costs(n, vector<int>(discounts + 1, INT_MAX));
        auto comp = [&](const array<int, 3>& a, const array<int, 3>& b) {return a[2] > b[2];};
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> pq(comp);
        // start point, distconts left, cost
        pq.push({0, discounts, 0});
        while (!pq.empty() && pq.top()[0] != n-1) {
            auto [start, disc, cost] = pq.top();
            pq.pop();
            for (auto[dest, toll] : graph[start]) {
                if (costs[dest][disc] > cost + toll) {
                    costs[dest][disc] = cost + toll;
                    pq.push({dest, disc, cost + toll});
                }
                if (disc > 0 && costs[dest][disc-1] > cost + toll / 2) {
                    costs[dest][disc-1] = cost + toll / 2;
                    pq.push({dest, disc-1, cost + toll/2});
                }
            }
        }
        return pq.empty() ? -1 : *min_element(costs[n-1].begin(), costs[n-1].end());
        
    }
};