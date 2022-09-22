/*
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/

#include "common.h"

class SolutionBackTrack {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> tmp_vec;
        dfs(s, 0, tmp_vec);
        return ans;
    }
    
    void dfs(string& str, int start, vector<string>& tmp_vec) {
        if (start >= str.size()) {
            ans.push_back(tmp_vec);
            return;
        }
        for (int i = 1; i <= str.size() - start; ++i){
            if (isPal(str.substr(start, i))) {
                tmp_vec.push_back(str.substr(start, i));
                dfs(str, start + i, tmp_vec);
                tmp_vec.pop_back();
            }
        }
        
    }
    
    bool isPal(const string& str) {
        int left = 0;
        int right = str.size() - 1;
        while (left < right) {
            if (str[left++] != str[right--])return false;
        }
        
        return true;
    }
};

class SolutionBackTrackDP {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp) {
        if (start >= s.length()) result.push_back(currentList);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};