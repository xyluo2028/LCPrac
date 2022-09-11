/*
Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
*/

#include "common.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int idx = 0;
        int tmp_cnt = 0;
        int N = words.size();
        while (idx < N) {
            int tmp_len = 0;
            tmp_cnt = 0;
            while (true) {
                if (idx + tmp_cnt >= N) break;
                if (tmp_len + words[idx + tmp_cnt].size() > maxWidth) break;
                tmp_len += words[idx + tmp_cnt].size();
                ++tmp_cnt;
                ++tmp_len; 
            }
            if (idx + tmp_cnt >= N) break;
            int space_cnt = 0;
            int space_res = 0;
            if (tmp_cnt > 1) {
                space_cnt = 1 + (maxWidth - tmp_len + 1) / (tmp_cnt - 1);
                space_res = (maxWidth - tmp_len + 1) % (tmp_cnt - 1);
            } else {
                space_cnt = 1 + (maxWidth - tmp_len + 1);
                space_res = maxWidth - tmp_len + 1;
            }
            
            string tmp_str = "";
            for (int i = 0; i < tmp_cnt; ++i) {
                tmp_str += words[idx + i];
                string tmp_space(space_cnt, ' ');
                if (space_res > 0) {
                    tmp_str += " ";
                    --space_res;
                }
                if (i < tmp_cnt - 1) {
                    tmp_str += tmp_space;
                }else if (space_res > 0) {
                    tmp_str += string(space_res, ' ');
                }
                
            }
            idx += tmp_cnt;
            //cout << tmp_str << endl;
            ans.push_back(tmp_str);
        }
        if (tmp_cnt > 0) {
            string tmp_str = "";
            for (int i = 0; i < tmp_cnt; ++i) {
                tmp_str += words[idx + i];
                if (tmp_str.size() < maxWidth) {
                    tmp_str += " ";
                }
            }
            while(tmp_str.size() < maxWidth) {
                tmp_str += " ";
            }
            //cout << tmp_str << endl;
            ans.push_back(tmp_str);
        }
        return ans;
    }
};