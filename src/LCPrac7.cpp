// LCPrac8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int buy = 0;
        int tmppro;
        int profit = 0;
        int len = prices.size();
        for (int i = 0; i < len; i++)
        {
            if (prices[i] < prices[buy]) buy = i;
            tmppro = prices[i] - prices[buy];
            profit = (tmppro > profit) ? tmppro : profit;
        }
        
        return profit;
    }

};

int main()
{
    vector<int> test = { 7,6,111,3,1 };
    Solution solve;
    int result = solve.maxProfit(test);
    cout << result << endl;
    
}
