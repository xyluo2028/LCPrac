#include "common.h"

class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        pair<int, int> startP;
        bool foundStart = false;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '*') {
                    startP.first = i;
                    startP.second = j;
                    foundStart = true;
                    break;
                }
            }
            if (foundStart) break;
        }
        return bfs(startP, grid);
        
    }
    
    int bfs(const pair<int, int>& start, vector<vector<char>>& grid) {
        queue<pair<int, int>> mQ;
        mQ.push(start);
        int steps = 0;
        while(!mQ.empty()) {
            int tmpSize = mQ.size();
            for (int i = 0; i < tmpSize; ++i) {
                pair<int,int> tmp = mQ.front();   
                if (takeOrNot({tmp.first, tmp.second+1}, grid)) {
                    if (grid[tmp.first][tmp.second+1] == '#') return steps+1;
                    grid[tmp.first][tmp.second+1] = '%';
                    mQ.push({tmp.first, tmp.second+1}); // east
                }
                if (takeOrNot({tmp.first+1, tmp.second}, grid)) {
                    if (grid[tmp.first+1][tmp.second] == '#') return steps+1;
                    grid[tmp.first+1][tmp.second] = '%';
                    mQ.push({tmp.first+1, tmp.second}); // south
                }
                if (takeOrNot({tmp.first, tmp.second-1}, grid)) {
                    if (grid[tmp.first][tmp.second-1] == '#') return steps+1;
                    grid[tmp.first][tmp.second-1] = '%';
                    mQ.push({tmp.first, tmp.second-1}); // west
                }
                if (takeOrNot({tmp.first-1, tmp.second}, grid)) {
                    if (grid[tmp.first-1][tmp.second] == '#') return steps+1;
                    grid[tmp.first-1][tmp.second] = '%';
                    mQ.push({tmp.first-1, tmp.second}); // north
                }
                grid[tmp.first][tmp.second] = '*';
                mQ.pop();
            }
            ++steps;
        }
        return -1;
    }
    
    bool takeOrNot(const pair<int, int>& point, vector<vector<char>>& grid) {
        if (point.first < 0 || point.second < 0) return false;
        if (point.first >= grid.size() || point.second >= grid[0].size()) return false;
        if (grid[point.first][point.second] == 'X' || 
            grid[point.first][point.second] == '*' || 
            grid[point.first][point.second] == '%') return false;
        return true;
    }
};