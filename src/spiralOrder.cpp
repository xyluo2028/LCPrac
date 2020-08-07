//[
//    [ 1, 2, 3,4 ],
//    [4, 5, 6, 7],
//    [7, 8, 9,10]
//]
// : [1, 2, 3, 6, 9, 8, 7, 4, 5]



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int turn0 = matrix[0].size()-1;
        int turn1 = matrix.size()-1;
        int turn2 = 0;
        int turn3 = 0;
        int vol = (turn0 + 1) * (turn1 + 1);
        while (true)
        {
            for (int i = turn2; i <= turn0; i++)
            {
                result.push_back(matrix[turn3][i]);
                cout << "a" << matrix[turn3][i] << endl;
            }
            turn3++;
            if (result.size() >= vol) break;
            for (int i = turn3; i <= turn1; i++)
            {
                result.push_back(matrix[i][turn0]);
                cout << "b" << matrix[i][turn0] << endl;
            }
            turn0--;
            if (result.size() >= vol) break;
            for (int i = turn0; i >= turn2; i--)
            {
                result.push_back(matrix[turn1][i]);
                cout << "c" << matrix[turn1][i] << endl;
            }
            turn1--;
            if (result.size() >= vol) break;
            for (int i = turn1; i >=turn3; i--)
            {
                result.push_back(matrix[i][turn2]);
                cout << "d" << matrix[i][turn2] << endl;
            }
            turn2++;
            if (result.size() >= vol) break;
        }
        return result;
    }
};


int main()
{
    Solution solve;
    vector<vector<int>> test = { { 1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10} };
    vector<int> result = solve.spiralOrder(test);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << ", ";
    }

}

