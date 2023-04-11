// car fleet, stack
#include "common.h"

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> pos_spd;
        int n = position.size();
        for (int i = 0; i < n; ++i) {
            pos_spd[position[i]] = speed[i];
        }
        stack<pair<int,int>> stk;
        for (auto it = pos_spd.rbegin(); it != pos_spd.rend(); ++it) {
            if (stk.empty() || !intersect(stk.top(), *it, target)) {
                stk.push(*it);
            }
        }
        return stk.size();
    }
    
    bool intersect(const pair<int, int>& p1, const pair<int, int>& p2, int target) {
        if (p1.first == p2.first) return true;
        if (p1.first < p2.first) return intersect(p2, p1, target);
        double p1_arr = (double)(target - p1.first) / p1.second;
        double p2_arr = (double)(target - p2.first) / p2.second;
       // cout << p1_arr << " " << p2_arr << endl;
        return p1_arr >= p2_arr;
    }
};