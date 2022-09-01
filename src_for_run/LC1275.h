#include "common.h"

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board;
        for (int i = 0; i < 3; ++i) {
            board.push_back(vector<int>(3, 0));
        }
        for (int i = 0; i < moves.size(); ++i) {
            board[moves[i][0]][moves[i][1]] = i % 2 == 0 ? 1 : -1; // 1 => x; -1 => o
        }
        // check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][1] + board[i][2] + board[i][0] == 3) return "A";
            else if (board[i][1] + board[i][2] + board[i][0] == -3) return "B";
        }
        // check column
        for (int i = 0; i < 3; ++i) {
            if (board[0][i] + board[1][i] + board[2][i] == 3) return "A";
            else if (board[0][i] + board[1][i] + board[2][i] == -3) return "B";
        }
        // diagonal
        if (board[0][0] + board[1][1] + board[2][2] == 3) return "A";
        else if (board[0][0] + board[1][1] + board[2][2] == -3) return "B";
        
        if (board[0][2] + board[1][1] + board[2][0] == 3) return "A";
        else if (board[0][2] + board[1][1] + board[2][0] == -3) return "B";
        if (moves.size() == 9) return "Draw";
        return "Pending";
    }
};

class Solution1{   
   string tictactoe(vector<vector<int>>& moves) {
      vector<int> A(8,0), B(8,0); // 3 rows, 3 cols, 2 diagonals
      for(int i=0; i<moves.size(); i++) {
          int r=moves[i][0], c=moves[i][1];
          vector<int>& player = (i%2==0)?A:B;
          player[r]++;
          player[c+3]++; 
          if(r==c) player[6]++;
          if(r==2-c) player[7]++;
      }
      for(int i=0; i<8; i++) {
          if(A[i]==3) return "A";
          if(B[i]==3) return "B";
      }
      return moves.size()==9 ? "Draw":"Pending";
  }
};