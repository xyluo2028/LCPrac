/*
Input: s = "3+2*2"
Output: 7
*/

#include "common.h"

class Solution {
public:
    int calculate(string s) {
        stack<int> mStack;
        int front = 0;
        int N = s.size();
        char sign = '+';
        string curr_num = "";
        while (front < N) {
            if (isNum(s[front])) {
                curr_num.push_back(s[front]);
            } 
            if (s[front] != ' ' && !isNum(s[front]) || front == N - 1) {
                int curr_num_i = atoi(curr_num.c_str());
                //cout << curr_num_i << endl;
                if (sign == '-') {
                    mStack.push(-curr_num_i);
                } else if (sign == '+') {
                    mStack.push(curr_num_i);
                } else if (sign == '*') {
                    int tmp_top = mStack.top();
                    mStack.pop();
                    mStack.push(tmp_top * curr_num_i);
                } else {
                    int tmp_top = mStack.top();
                    mStack.pop();
                    mStack.push(tmp_top / curr_num_i);
                }
                sign = s[front];
                curr_num.clear();
            } 
            ++front;
        }
        
        int ans = 0;
        while (!mStack.empty()){
            ans += mStack.top();
            mStack.pop();
        }
        return ans;
    }
    
    bool isNum(char c) {
        int num = (int)(c - '0');
        return num >= 0 && num < 10;
    }
};