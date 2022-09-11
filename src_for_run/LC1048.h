#include "common.h"

bool comp (string str1, string str2) {
    return str1.size() < str2.size();
}

class Solution1048Dp {
public:
    int longestStrChain(vector<string>& words) {
        int N = words.size();
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int> dp;
        dp[words[0]] = 1;
        int ans = 1;
        for (int i = 1; i < words.size(); ++i) {
            int pred_len = 1;
            for(int j = 0; j < words[i].size(); ++j) {
                string tmp_str = words[i].substr(0, j - 0) + words[i].substr(j + 1);
                if (dp.find(tmp_str) != dp.end()) {
                     pred_len = max(pred_len, 1 + dp[tmp_str]);
                }
            }
            dp[words[i]] = pred_len;
            ans = max(ans, dp[words[i]]);
        }
        return ans;
    }
    
};

class Solution1048DFS {
public:
    unordered_set<string> m_set;
    unordered_map<string, int> m_map;
    int longestStrChain(vector<string>& words) {
        for (auto& w : words) {
            m_set.emplace(w);
        }
        int ans = 1;
        for (auto& w : words) {
            ans = max(ans, dfs(w));
        }
        return ans;
    }
    
    int dfs(const string& word) {
        if (m_map.find(word) != m_map.end()) {
            return m_map[word];
        }
        int ans = 1;
        for (int i = 0; i < word.size(); ++i) {
            string tmp_str = word.substr(0, i) + word.substr(i+1);
            if (m_set.find(tmp_str) != m_set.end()) {
                int curr_len = 1 + dfs(tmp_str);
                ans = max(ans, curr_len);
            } 
        }
        m_map[word] = ans;
        return ans;
    }
};