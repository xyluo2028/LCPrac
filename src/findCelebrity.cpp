// LCPrac12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

bool knows(int a, int b) {
    vector<vector<int>> fames = { {1,1,0}, {0,1,0}, {1,1,1} };
    if (fames[a][b] == 1) return true;
    else return false;
}

class Solution {
public:
    int findCelebrity(int n) {
        if (n < 2) return -1;
        int elem = 0;
        for (size_t i = 1; i < n; i++) //row
        {
            if (knows(elem, i)) {
                elem = i;
            }
        }
        if (check_col(elem, n) && check_row(elem, n)) return elem;
        else return -1;
    }

private:
    bool check_col(int col, int n) {
        for (size_t i = 0; i < n; i++)
        {
            if (!knows(i, col)) return false;

        }
        return true;
    }
    bool check_row(int row, int n) {
        for (size_t i = 0; i < n; i++)
        {
            if (i == row) continue;
            if (knows(row, i)) return false;

        }
        return true;
    }

};

int main()
{
    Solution solve;
    int result = solve.findCelebrity(3);
    cout << result << endl;
}

