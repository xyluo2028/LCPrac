/*
kadanes algorithm
*/

#include "common.h"

class Solution {
public:
    int largestVariance(string s) {
        vector<int>freq(26, 0);
        for (auto& chr : s) {
            freq[chr - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {    // upper
            for (int j = 0; j< 26; ++j) { // under
                int remainI = freq[i];
                int remainJ = freq[j];
                if (i == j || remainI == 0 || remainJ == 0) continue;
                int cntI = 0;
                int cntJ = 0;
                int tmpVar = 0;
                //cout << i << ", " << j << endl;
                for (int k = 0; k < s.size(); ++k) {
                    if (s[k]-'a' == i) {
                        ++cntI;
                        --remainI;
                    }
                    if (s[k]-'a' == j) {
                        ++cntJ;
                        --remainJ;
                    }
                    if (cntJ > 0)
                        tmpVar = (cntI - cntJ) > tmpVar ? (cntI - cntJ) : tmpVar;
                    
                    //cout << cntI << "; " << cntJ << "; " << tmpVar << endl;
                    if (cntI < cntJ && remainJ > 0) {
                        cntI = 0;
                        cntJ = 0;
                    }
                } // end for k
                ans = ans > tmpVar ? ans : tmpVar;
            } // end for j 
        } // end for i
        return ans;
    }
};