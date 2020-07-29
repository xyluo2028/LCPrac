// LCPrac11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if (m == 0) {
            A = B;
            return;
        }
        size_t tracer = 0;
        for (size_t j = 0; j < n; j++)
        {
            for (size_t i = tracer; i < m+n; i++)
            {
                if (B[j] < A[i])
                {
                    A.insert(A.begin() + i, 1, B[j]);
                }
                else if (B[j] >= A[i] && i == m + j - 1) {
                    A.insert(A.begin() + i + 1, 1, B[j]);

                }
                else continue;
                A.pop_back();
                tracer = i + 1;
                break;
            }
        }
    }
};

int main()
{
    vector<int> test1 = { 1, 3, 4, 7, 9,0, 0, 0 };
    vector<int> test2 = { 2, 4, 6 };
    Solution solve;
    solve.merge(test1, 5, test2, 3);
    cout << test1[1] << endl;
}

