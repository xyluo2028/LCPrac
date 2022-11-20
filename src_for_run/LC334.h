/*
Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and 
nums[i] < nums[j] < nums[k]. If no such indices exists, return false.
*/

#include "common.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minimum = INT_MAX;
        int minimum1 = INT_MAX;
        for (auto& num : nums) {
            if (num <= minimum) {
                minimum = num;
            } else if (num <= minimum1) {
                minimum1 = num;
            } else if (num > minimum1){
                return true;
            }
        }
        return false;
    }
};