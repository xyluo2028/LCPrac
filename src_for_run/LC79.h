// backtrack idea

#include "common.h"

class Solution {
public:
    vector<vector<char>> m_board;
    string m_word;
    bool exist(vector<vector<char>>& board, string word) {
        m_board = board;
        m_word = word;
        int height = board.size();
        int width = board[0].size(); 
        int len = 0;
        pair<int, int> tmp_pos;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                //cout << "exist " << i << " : " << j << endl;
                len = 0;
                tmp_pos = {i, j};
                if (board[i][j] != word[0]) {
                    continue;
                } else {
                    if (moveForward(len, tmp_pos)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool moveForward(int len, pair<int, int> pos) {
        //cout << len << " : " << pos.first << " : " << pos.second << endl;
        //cout << word[len] << endl;
        if (len == m_word.size() - 1) return true;
        m_board[pos.first][pos.second] = '#';
        // move right
        pair<int, int> tmp_pos = {pos.first, pos.second + 1};
        if (pos.second + 1 < m_board[0].size() && 
            m_board[pos.first][pos.second + 1] == m_word[len + 1]) {
            if (moveForward(len + 1, tmp_pos)) {
                return true;
            }
        }
        // move down
        tmp_pos = {pos.first + 1, pos.second};
        if (pos.first + 1 < m_board.size() && 
            m_board[pos.first + 1][pos.second] == m_word[len + 1]) {
            if (moveForward(len + 1, tmp_pos)) {
                return true;
            }
        }
        // move left
        tmp_pos = {pos.first, pos.second - 1};
        if (pos.second - 1 >= 0 && 
            m_board[pos.first][pos.second - 1] == m_word[len + 1]) {
            if (moveForward(len + 1, tmp_pos)) {
                return true;
            }
        }
        // move up
        tmp_pos = {pos.first - 1, pos.second};
        if (pos.first - 1 >= 0 && 
            m_board[pos.first - 1][pos.second] == m_word[len + 1]) {
            if (moveForward(len + 1, tmp_pos)) {
                return true;
            }
        }
        m_board[pos.first][pos.second] = m_word[len];
        return false;
    }   
    
};