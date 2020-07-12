// LCPrac37.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (k == 1) return matrix[0][0];
        int n = matrix.size();
        vector<int> container(n * n);
        for (int i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++)
            {
                container[i * n + j] = matrix[i][j];
            }
        }
        sort(container.begin(), container.end());
        return container[k - 1];

    }
};

int main()
{
    Solution solve;
    vector<vector<int>> test{ {1, 5, 9}, {10, 11, 13 }, {12, 13, 15}};
    int result = solve.kthSmallest(test, 8);
    cout << result << endl;
}


