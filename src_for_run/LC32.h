// Longest Valid Parentheses
/*
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
*/
#include "common.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n < 2) return 0;
        int ans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};