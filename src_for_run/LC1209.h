/*
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
*/

#include "common.h"

class Solution1209 {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> counts;
        for (int i = 0; i < s.size(); ++i) {
            if (counts.empty() || s[i] != counts.back().second) {
                counts.push_back({ 1, s[i] });
            } else if (++counts.back().first == k) {
                 counts.pop_back();
            }
        }
        s = "";
        for (auto &p : counts) {
            s += string(p.first, p.second);
        }
        return s;
    }
};

class Solution1209_1 {
public:
    string removeDuplicates(string s, int k) {
        stack<int> mStack;
        for (int i = 0; i < s.size(); ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                mStack.push(1);
            } else if (++mStack.top() == k) {
                mStack.pop();
                s.erase(i - k + 1, k);
                i = i - k;
            }
        }
        return s;
    }
};

