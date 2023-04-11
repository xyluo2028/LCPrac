// Count of Smaller Numbers After Self
/*
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
*/
#include "common.h"

class Solution {
public:
    vector<int> ans;
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.clear();
        ans.resize(n, 0);
        vector<int> indices(n, 0);
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }
        mergeSort(nums, indices, 0, n);
        return ans;
    }
    void mergeSort(vector<int>& nums, vector<int>& indices, int lo, int hi) {
        if (hi - lo <= 1) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(nums, indices, lo, mid);
        mergeSort(nums, indices, mid, hi);
        merge(nums, indices, lo, hi, mid);
    }
    
    void merge(vector<int>& nums, vector<int>& indices, int lo, int hi, int mid) {
        int i = lo;
        int j = mid;
        vector<int> tmp_inds;
        while (i < mid && j < hi) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                ans[indices[i]] += j - mid;
                tmp_inds.push_back(indices[i]);
                i++;
            } else {
                tmp_inds.push_back(indices[j]);
                j++;
            }
        }
        while (i < mid) {
            ans[indices[i]] += j - mid;
            tmp_inds.push_back(indices[i]);
            i++;
        }
        while (j < hi) {
            tmp_inds.push_back(indices[j]);
            j++;
        }
        for (int k = 0; k < hi - lo; ++k) {
            indices[lo + k] = tmp_inds[k];
        }
    }
    
};