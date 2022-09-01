/*
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