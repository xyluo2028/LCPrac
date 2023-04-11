// Maximum Product of the Length of Two Palindromic Subsequences
// use bitmap to check if two subseq are disjoint
#include "common.h"
class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        int maxBm = (1 << n) - 1;
        unordered_map<int, size_t> umap;
        for (int i = 1; i < maxBm; ++i) {
            string tmp_str = "";
            for (int j = 0; j <= n; ++j) {
                if ((i >> j) % 2) {
                    tmp_str.push_back(s[n-j-1]);
                }
            }
            //cout << tmp_str << endl;
            if (isPal(tmp_str)) {
                umap[i] = tmp_str.size();
            }
        }
        int ans = 0;
        for (auto it = umap.begin(); it != umap.end(); ++it) {
            for (auto it1 = next(it); it1 != umap.end(); ++it1) {
                if ((it->first & it1->first) == 0) {
                    int prod = it->second * it1->second;
                    ans = ans > prod ? ans : prod;
                }
            }
        }
        return ans;
    }

    bool isPal(string& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};