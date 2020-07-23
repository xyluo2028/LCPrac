// LCPrac25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result = { 0 };
        if (n == 0) return result;
        result = grayCode(n - 1);
        int addon = 1 << (n - 1);
        int len = result.size();
        for( int i = len-1; i>-1; i--)
        {
            result.push_back(addon + result[i]);
            cout << result.back() << endl;
        }
        return result;
    }
};

int main()
{
    Solution solve;
    int n = 2;
    vector<int> result = solve.grayCode(n);
    cout << result[2] << endl;
}


