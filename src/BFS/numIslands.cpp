class Solution {
public:
    int ans;
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        ans = 0;
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1') bfs(grid, i, j);
            }
        }
        return ans;
    }
private:
    void bfs(vector<vector<char>>& grid, int row, int vec) {
        queue<pair<int,int>> myQ;
        myQ.push(make_pair(row, vec));
        pair<int, int> tmp;
        grid[row][vec] = '2';
        while (!myQ.empty())
        {
            tmp.first = myQ.front().first - 1;
            tmp.second = myQ.front().second;
            if (tmp.first >= 0 && grid[tmp.first][tmp.second] == '1') {
                myQ.push(tmp);
                grid[tmp.first][tmp.second] = '2';
            }
            tmp.first = myQ.front().first + 1;
            tmp.second = myQ.front().second;
            if (tmp.first < grid.size() && grid[tmp.first][tmp.second] == '1') {
                myQ.push(tmp);
                grid[tmp.first][tmp.second] = '2';
            }
            tmp.first = myQ.front().first;
            tmp.second = myQ.front().second - 1;
            if (tmp.second >= 0 && grid[tmp.first][tmp.second] == '1') {
                myQ.push(tmp);
                grid[tmp.first][tmp.second] = '2';
            }
            tmp.first = myQ.front().first;
            tmp.second = myQ.front().second + 1;
            if (tmp.second < grid[0].size() && grid[tmp.first][tmp.second] == '1') {
                myQ.push(tmp);
                grid[tmp.first][tmp.second] = '2';
            }
            myQ.pop();
        }
        ans++;
    }
};
