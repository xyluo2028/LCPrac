// LCPrac7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.empty()) return result;
        if (strs.size() == 1) return strs[0];
        int idx = 0;
        int len = strs.size();
        bool flag = true;
        char elem;
        while (flag)
        {
            elem = strs[0][idx];
            for (size_t i = 1; i < len; i++)
            {
                if (strs[i].size()<= idx)
                {
                    flag = false;
                    break;
                }
                else if (strs[i][idx] != elem)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                result.push_back(elem);
                idx++;
            }
            
        }
        return result;
    }
};

int main()
{
    vector<string> test = { "" };
    Solution solve;
    string result = solve.longestCommonPrefix(test);
    cout << result << endl;
}
