//Minimum Cost to Reach City With Discounts
#include "common.h"

int minimumCost(int n, vector<vector<int>>& highways, int discounts) {    
    vector<vector<pair<int, int>>> hsprty(n);
    for (auto &h : highways) {
        hs[h[0]].push_back({h[1], h[2]});
        hs[h[1]].push_back({h[0], h[2]});
    }
    vector<vector<int>> costs(n, vector<int>(discounts + 1, INT_MAX));
    auto cmp = [](const array<int, 3> &a, const array<int, 3> &b) { return a[0] > b[0]; };
    priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> pq(cmp);
    pq.push({0, discounts, 0});
    while(!pq.empty() && pq.top()[2] != n - 1) {
        auto [cost, disc, i] = pq.top(); pq.pop();
        for (auto [j, toll] : hs[i]) {
            if (costs[j][disc] > cost + toll) {
                costs[j][disc] = cost + toll;
                pq.push({costs[j][disc], disc, j});
            }
            if (disc > 0 && costs[j][disc - 1] > cost + toll / 2) {
                costs[j][disc - 1] = cost + toll / 2;
                pq.push({costs[j][disc - 1], disc - 1, j});
            }
        }
    }
    return pq.empty() ? -1 : *min_element(begin(costs[n - 1]), end(costs[n - 1]));
}