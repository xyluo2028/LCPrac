// Swim in Rising Water
#include "common.h"

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        auto comp = [&grid](pair<int, int>& p1, pair<int, int>& p2) {
            return grid[p1.first][p1.second] > grid[p2.first][p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        int ans = grid[0][0];
        pq.push({0,0});
        unordered_set<int> searched;
        searched.emplace(grid[0][0]);
        while (!pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            if (x == n - 1 && y == n - 1) {
                ans = ans > grid[n-1][n-1] ? ans : grid[n-1][n-1];
                break;
            }
            ans = grid[x][y] > ans ? grid[x][y] : ans;
            if (y + 1 < n && searched.count(grid[x][y+1]) == 0) {
                pq.push({x, y+1});
                searched.emplace(grid[x][y+1]);
            }
            if (x + 1 < n && searched.count(grid[x+1][y]) == 0) {
                pq.push({x+1, y});
                searched.emplace(grid[x+1][y]);
            }
            if (y - 1 >= 0 && searched.count(grid[x][y-1]) == 0) {
                pq.push({x, y-1});
                searched.emplace(grid[x][y-1]);
            }
            if (x - 1 >= 0 && searched.count(grid[x-1][y]) == 0) {
                pq.push({x-1, y});
                searched.emplace(grid[x-1][y]);
            }
        }
        return ans;
    }
};