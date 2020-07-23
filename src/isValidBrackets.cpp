// LCPrac24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

map<char, int> CharInt{ {'{', -3}, {'[', -2}, {'(', -1}, {' ', 0}, {')', 1}, {']', 2}, {'}', 3} };

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<int> tmpStack;
        int length = s.size();
        int tmp;
        int tmp1;
        for (size_t i = 0; i < length; i++)
        {
            tmp1 = CharInt[s[i]];
            if (tmp1 > 0) {
                if (tmpStack.empty()) return false;
                else {
                    tmp = tmpStack.top();
                    if (tmp + tmp1 == 0) tmpStack.pop();
                    else return false;
                }
            }
            else if (tmp1 < 0) tmpStack.push(tmp1); 
        }
        bool result = tmpStack.empty() ? true : false;
        return result;
    }
};

int main()
{
    Solution solve;
    string test = "{{[  {}}";
    bool result = solve.isValid(test);
    cout << result << endl;
}

