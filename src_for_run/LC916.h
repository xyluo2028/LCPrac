// Word Subsets
#include "common.h"

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<vector<int>> table;
        for (auto& word : words1) {
            vector<int> vec(26, 0);
            for (auto& c : word) {
                vec[c-'a']++;
            }
            table.push_back(vec);
        }
        vector<int> table2(26, 0);
        for (auto& word : words2) {
            vector<int> vec(26, 0);
            for (auto& c : word) {
                vec[c-'a']++;
            }
            for (int i = 0; i < 26; ++i) {  // maximum count of every letter in each word in words2
                if (vec[i] > table2[i]) {
                    table2[i] = vec[i];
                }
            }
        }
        vector<string> ans;
        for (int i = 0; i < words1.size(); ++i) {
            bool flag = true;
            for (int j = 0; j < 26; ++j) {
                if (table[i][j] < table2[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(words1[i]);
        }
        return ans;
    }
};