/*
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
*/

#include "common.h"

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> time_mod_sixty(60, 0);
        for (int i = 0; i < time.size(); ++i) {
            ++time_mod_sixty[time[i] % 60];
        }
        int i = 1;
        int j = 59;
        long long ansL = 0;
        while(i < j) {
            ansL += (long long)time_mod_sixty[i] * time_mod_sixty[j];
            ++i;
            --j;
        }
        if (time_mod_sixty[0] > 1) {
            ansL += (long long)time_mod_sixty[0] * (time_mod_sixty[0] - 1) / 2;
        }
        if (time_mod_sixty[30] > 1) {
            ansL += (long long)time_mod_sixty[30] * (time_mod_sixty[30] - 1) / 2;
        }
        return (int)ansL;
    }
};