#include "common.h"

class Solution1044 {
public:
    int ans_idx;
    int ans_len;
    string longestDupSubstring(string s) {
        int N = s.size();
        int left = 0;
        int right = N - 1;
        ans_idx = -1;
        ans_len = 0;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if (RabinKarp(s, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (ans_len <= 0) return "";
        string ans = s.substr(ans_idx, ans_len);
        return ans;
    }
    
    bool RabinKarp(string& s, int len) {
        if (len == 0) return true;
        int moder = 1000000007;
        long long hash = 0;
        for (int i = 0; i < len; ++i) {
            hash = ((int)(s[i] - 'a') + hash * 26) % moder;
        }
        long long multi = 1;
        for (int i = 0; i < len; ++i) {
            multi = (multi * 26) % moder;
        }
        //unordered_map<int, vector<int>> umap;
        //umap[hash].push_back(0);
        unordered_map<int, int> umap;
        umap[hash] = 0;
        int n = s.size();
        for (int i = 1; i <= n - len; ++i) {
            hash = (hash * 26 - (int)(s[i - 1] - 'a') * multi % moder + moder) % moder;
            hash = (hash + (int)(s[i + len - 1] - 'a')) % moder;
            if (umap.find(hash) != umap.end()) {
                /*
                for (int& v : umap[hash]) {
                    if (s.substr(v, len).compare(s.substr(i, len)) == 0) {
                        ans_idx = i;
                        ans_len = len;
                        return true;
                    }
                }*/
                int v = umap[hash];
                if (s.substr(v, len).compare(s.substr(i, len)) == 0) {
                    ans_idx = i;
                    ans_len = len;
                    return true;
                }
            }
            //umap[hash].push_back(i);
            umap[hash] = i;
        }
        return false;
    }
    
};