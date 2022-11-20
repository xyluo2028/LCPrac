/*
Let's define a function countUniqueChars(s) that returns the number of unique characters on s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.
      B
    C B
  B C B
A B C B
*/
#include "common.h"

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> lastPos(26, 0);
        vector<int> contrib(26, 0);
        int N = s.size();
        int ans = 0;
        int curr = 0;
        for (int i = 0; i < N; ++i) {
            curr -= contrib[s[i]-'A'];
            contrib[s[i]-'A'] = i + 1 - lastPos[s[i]-'A'];
            curr += contrib[s[i]-'A'];
            ans += curr;
            lastPos[s[i]-'A'] = i+1;
        }
        return ans;
    }
};