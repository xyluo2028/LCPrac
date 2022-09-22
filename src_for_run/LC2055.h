/*
Input: s = "**|**|***|", queries = [[2,5],[5,9]]
Output: [2,3]
Explanation:
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.

PreSum lower/upperBound
*/

#include "common.h"

class Solution2055A {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> guards;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '|') guards.push_back(i);
        }
        vector<int> ans;
        for (auto& q : queries) {
            int left = lower_bound(guards.begin(), guards.end(), q[0]) - guards.begin();
            int right = upper_bound(guards.begin(), guards.end(), q[1]) - guards.begin() - 1;
            if (left < right) {
                ans.push_back(guards[right] - guards[left] - (right - left));
            } else {
                ans.push_back(0);
            }
        }
        return ans;        
    }
};

class Solution2055B {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int N = s.size();
        vector<int> pSum(N, 0);
        vector<int> rBound(N + 1, 0);
        int tmpS = 0;
        for (int i = 0; i < N; ++i) {
            tmpS = s[i] == '|' ? tmpS + 1 : tmpS;
            pSum[i] = tmpS;
            rBound[i + 1] = s[i] == '|' ? i : rBound[i];
        }
        vector<int> lBound(N + 1);
        lBound[N] = 100001;
        for (int i = N - 1; i >= 0; --i) {
            lBound[i] = s[i] == '|' ? i : lBound[i + 1];
        }
        vector<int> ans;
        for (auto& q : queries) {
            int left = lBound[q[0]];
            int right = rBound[q[1] + 1];
            if (left < right) {
                ans.push_back(right - left - (pSum[right] - pSum[left]));
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};