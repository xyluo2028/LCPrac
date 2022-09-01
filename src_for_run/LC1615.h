// how to describe that two values are connected ?  2d-array or hash_set

#include "common.h"

class Solution1 {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> connected;
        for (int i = 0; i < n; ++i) {
            connected.push_back(vector<int>(n, 0));
        }
        vector<int> connects(n, 0);
        for (auto road : roads) {
            connected[road[0]][road[1]] = 1;
            connected[road[1]][road[0]] = 1;
            connects[road[0]]++;
            connects[road[1]]++;
        }
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i+1; j< n; ++j) {
                int tmp = connects[i] + connects[j];
                if (connected[i][j]) tmp--;
                if (tmp > ans) ans = tmp;
            }
        }
        return ans;
    } 
};

class Solution2 {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_set<string> m_set;
        vector<int> connects(n, 0);
        for (auto road : roads) {
            string str_road = to_string(road[0]) + "x" + to_string(road[1]);
            m_set.emplace(str_road);
            connects[road[0]]++;
            connects[road[1]]++;
        }
        
        auto is_connected = [&m_set](int a, int b) {
            string tmp = to_string(a) + "x" + to_string(b);
            string rev_tmp = to_string(b) + "x" + to_string(a);
            return (m_set.find(tmp) != m_set.end() || m_set.find(rev_tmp) != m_set.end());
        };
        
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i+1; j< n; ++j) {
                int tmp = connects[i] + connects[j];
                if (is_connected(i, j)) tmp--;
                if (tmp > ans) ans = tmp;
            }
        }
        return ans;
    } 
};