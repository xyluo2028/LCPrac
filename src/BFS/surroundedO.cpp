#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> states;
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        states.resize(board.size());
        int veclen = board[0].size();
        for (int i=0; i<states.size(); i++)
        {
            states[i].assign(veclen, 0);
        }
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (states[i][j]==0 && board[i][j] == 'O') bfs(board, i, j);
            }
        }
        return;
    }

private:
    void bfs(vector<vector<char>>& board, int row, int vec) {
        queue<pair<int, int>> myQ;
        set<pair<int, int>> mySet;
        myQ.push(make_pair(row, vec));
        mySet.emplace(make_pair(row, vec));
        bool flag = false;
        pair<int, int> tmp;
        while (!myQ.empty())
        {
            if (myQ.front().first == 0 || myQ.front().first == board.size() - 1 || myQ.front().second == 0 || myQ.front().second == board[0].size() - 1) {
                flag = true;
            }
            tmp.first = myQ.front().first - 1;
            tmp.second = myQ.front().second;
            if (tmp.first >= 0 && mySet.find(tmp) == mySet.end() && board[tmp.first][tmp.second] == 'O') {
                myQ.push(tmp);
                mySet.emplace(tmp);
            }
            tmp.first = myQ.front().first + 1;
            tmp.second = myQ.front().second;
            if (tmp.first < board.size() && mySet.find(tmp) == mySet.end() && board[tmp.first][tmp.second] == 'O') {
                myQ.push(tmp);
                mySet.emplace(tmp);
            }
            tmp.first = myQ.front().first;
            tmp.second = myQ.front().second - 1;
            if (tmp.second >= 0 && mySet.find(tmp) == mySet.end() && board[tmp.first][tmp.second] == 'O') {
                myQ.push(tmp);
                mySet.emplace(tmp);
            }
            tmp.first = myQ.front().first;
            tmp.second = myQ.front().second + 1;
            if (tmp.second < board[0].size() && mySet.find(tmp) == mySet.end() && board[tmp.first][tmp.second] == 'O') {
                myQ.push(tmp);
                mySet.emplace(tmp);
            }
            myQ.pop();
        }
        for (auto point:mySet)
        {
            states[point.first][point.second] = 1;
            if(!flag) board[point.first][point.second] = 'X';
        }
        return;
    }
};

int main() {
    Solution solve;
    vector<vector<char>> test = { {'O', 'O', 'O'},{'O', 'O', 'O'}, {'O', 'O', 'O'} };
    solve.solve(test);
    for (auto line:test)
    {
        for (auto item : line)
        {
            cout << item << ",";
        }
        cout << endl;
    }
}
