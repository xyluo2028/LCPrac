// LCPrac12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        boardwidth = n;
        board.resize(n);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                board[i].push_back(0);
            }
        }
    }

    int move(int row, int col, int player) {
        int check_row;
        int check_col;
        int check_diag0;
        int check_diag1;
        if (board[row][col] != 0) return 0;
        switch (player)
        {
        case 1:
            board[row][col] = -1;
            check_row = sum_row(row);
            check_col = sum_col(col);
            if (check_row == -boardwidth || check_col == -boardwidth) return 1;
            else if(row == col) {
                check_diag0 = sum_diag0();
                if (check_diag0 == -boardwidth) return 1;
            }
            if (row + col == boardwidth - 1) {
                cout << "diag1" << endl;
                check_diag1 = sum_diag1();
                if (check_diag1 == -boardwidth) return 1;
            }
            break;

        case 2:
            board[row][col] = 1;
            check_row = sum_row(row);
            check_col = sum_col(col);
            if (check_row == boardwidth || check_col == boardwidth) return 2;
            else if (row == col) {
                check_diag0 = sum_diag0();
                if (check_diag0 == boardwidth) return 2;
            }
            if (row + col == boardwidth - 1) {
                check_diag1 = sum_diag1();
                if (check_diag1 == boardwidth) return 2;
            }
            break;
        }
        return 0;
    }

private:
    vector<vector<int>> board;
    int boardwidth;

    int sum_row(int row) {
        int sum = 0;
        for (size_t i = 0; i < boardwidth; i++)
        {
            sum += board[row][i];
        }
        return sum;
    }

    int sum_col(int col) {
        int sum = 0;
        for (size_t i = 0; i < boardwidth; i++)
        {
            sum += board[i][col];
        }
        return sum;
    }

    int sum_diag0() {
        int sum = 0;
        for (size_t i = 0; i < boardwidth; i++)
        {
            sum += board[i][i];
        }
        return sum;
    }

    int sum_diag1() {
        int sum = 0;
        for (size_t i = 0; i < boardwidth; i++)
        {
            sum += board[i][boardwidth - i - 1];
        }
        return sum;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main()
{
    TicTacToe* obj = new TicTacToe(3);
    int param_1 = obj->move(1, 2, 2);
    int param_2 = obj->move(0, 2, 1);
    int param_3 = obj->move(0, 0, 2);
    int param_4 = obj->move(2, 0, 1);
    int param_5 = obj->move(1, 1, 1);
    cout << param_5 << endl;
    delete obj;
}

