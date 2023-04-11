/* Interleaving String */
#include "common.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (n1 + n2 != n3) return false;
        vector<vector<int>> memo(n1, vector<int>(n2, -1));
        return recur(s1, 0, s2, 0, s3, 0, memo);
    }
    
    bool recur(string& s1, int i, string& s2, int j, string& s3, int k, vector<vector<int>>& memo){
        if (i == s1.size()) {
            return s2.substr(j).compare(s3.substr(k)) == 0;
        }
        if (j == s2.size()) {
            return s1.substr(i).compare(s3.substr(k)) == 0;
        }
        if (memo[i][j] >= 0) return memo[i][j] > 0;
        bool ans = false;
        if (s3[k] == s1[i] && recur(s1, i+1, s2, j, s3, k+1, memo) || s3[k] == s2[j] && recur(s1, i, s2, j+1, s3, k+1, memo)) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
};