/*
You are given a string s consisting only of characters 'a' and 'b'​​​​.
You can delete any number of characters in s to make s balanced. 
s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
Return the minimum number of deletions needed to make s balanced.
*/

// good trick of reversing string by a stack

#include "common.h"

class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> m_stack;
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (!m_stack.empty() && s[i] > m_stack.top()) {
                m_stack.pop();
                ++ans;
            } else {
                m_stack.push(s[i]);
            }
        }
        return ans;
    }
};