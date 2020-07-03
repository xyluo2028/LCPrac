// LCPrac9.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ascll_space = 32

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int ASCList[13] = {32, 43, 45, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };

class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int signascll = 43;
        int idx = 0;
        bool start = false;
        bool forcebreak = false;
        int tmp;
        vector<int> numcontainer;
        while (idx < len && forcebreak == false)
        {
            tmp = Judge(str[idx]);
            switch (tmp)
            {
            case -1:
                forcebreak = true;
                break;
            case 32:
                if (start == true) forcebreak = true;
                break;

            case 43:
            case 45:
                if (start == false)
                {
                    start = true;
                    signascll = tmp;
                }
                else {
                    forcebreak = true;
                }
                break;

            case 48:
            case 49:
            case 50:
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            case 56:
            case 57:
                if (start == false) start = true;
                numcontainer.push_back(tmp - 48);
                break;
            }
            idx++;
        }
        int num_len = numcontainer.size();
        if (num_len == 0) return 0;
        long long result = 0;
        int firstnonzero = FirstNonZero(numcontainer);
        if (num_len- firstnonzero > 10) {
            result = (signascll == 43) ? 2147483647 : -2147483648;
            return result;
        }
        for (size_t i = firstnonzero; i < num_len; i++)
        {
            result += numcontainer[i] * pow(10, num_len - i - 1);
        }
        result = result * (44 - signascll);
        if (result >= 2147483648) result = 2147483647;
        else if (result < -2147483648) result = -2147483648;
        return (int)result;
    }

private:
    int Judge(char c) {
        int asc_c = (int)c;
        int result = -1;
        for (size_t i = 0; i < 13; i++)
        {
            if (asc_c == ASCList[i]) {
                result = ASCList[i];
                break;
            }
        }
        return result;
    }

    int FirstNonZero(vector<int> input) {
        int result = 0;
        int len = input.size();
        for (size_t i = 0; i < len; i++)
        {
            if (input[i] != 0) break;
            else result++;
        }
        return result;
    }
};


int main()
{
    string a = "00000000200000";
    Solution solve;
    int test_result = solve.myAtoi(a);
    cout << test_result << endl;
}
