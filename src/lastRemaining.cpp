// LCPrac33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 0) return 0;
        int x = lastRemaining(n - 1, m);
        return (m + x) % n;
    }
//private:
//    int recurF(int n, int m) {
//        if (n == 0) return 0;
//        int x = recurF(n - 1, m);
//        return (m + x) % n;
//    }
};

int main()
{
    Solution solve;
    int result = solve.lastRemaining(5, 3);
    cout << result << endl;
}

