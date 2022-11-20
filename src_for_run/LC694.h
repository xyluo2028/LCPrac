/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of distinct islands.
*/
#include "common.h"

class Solution {
public:
    vector<vector<bool>> seen;
    int m;
    int n;
    int numDistinctIslands(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        unordered_set<string> uset;
        seen.resize(m, {vector<bool>(n, false)});
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!seen[i][j] && grid[i][j] == 1) {
                    string path = "O";
                    search(grid, i, j, path);
                    uset.emplace(path);
                   // cout << path << endl;
                }
            }
        }
        return uset.size();
    }
    
    void search(vector<vector<int>>& grid, int row, int col, string& path) {
        seen[row][col] = true;
        if (col + 1 < n && grid[row][col+1]==1 && !seen[row][col+1]) {
            path.push_back('R');
            search(grid, row, col + 1, path);
        }
        if (row + 1 < m && grid[row+1][col]==1 && !seen[row+1][col]) {
            path.push_back('D');
            search(grid, row + 1, col, path);
        }
        if (col - 1 >= 0 && grid[row][col-1]==1 && !seen[row][col-1]) {
            path.push_back('L');
            search(grid, row, col - 1, path);
        }
        if (row - 1 >= 0 && grid[row-1][col]==1 && !seen[row-1][col]) {
            path.push_back('U');
            search(grid, row - 1, col, path);
        }
        path.push_back('O');
    }
};