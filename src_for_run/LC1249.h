/*Each prefix of a balanced parentheses has a number of open parentheses greater or equal than 
closed parentheses, similar idea with each suffix.*/

#include "common.h"

class Solution1249 {
public:
    string minRemoveToMakeValid(string s) {
        int balance = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++balance;
            } else if (s[i] == ')') {
                if (balance > 0) {
                    --balance;
                } else {
                    s.erase(s.begin() + i);
                    --i;
                }
            }
        }
        balance = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                ++balance;
            } else if (s[i] == '(') {
                if (balance > 0) {
                    --balance;
                } else {
                    s.erase(s.begin() + i);
                }
            } 
        } 
        return s;
    }
};