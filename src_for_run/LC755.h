//  Pour Water
#include "common.h"
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        for (int i = 0; i < volume; ++i) {
            int curr = k;
            // one water drop move left
            while (curr - 1 >= 0 && heights[curr] + 1 > heights[curr - 1]) {
                curr--;
            }
            // move right
            while (curr + 1 < heights.size() && heights[curr] + 1 > heights[curr + 1]) {
                curr++;
            }
            // move to k
            while (curr > k && heights[curr] + 1 > heights[curr - 1]) {
                curr--;
            }
            heights[curr]++;
        }
        return heights;
    }
};