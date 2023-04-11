// Count of Range Sum
/*
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.
*/
#include "common.h"

class Solution {
public:
    int ans;
    int m_lower;
    int m_upper;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> preSum(n+1, 0);
        ans = 0;
        m_lower = lower;
        m_upper = upper;
        for (int i = 1; i <= n; ++i) {
            preSum[i] = preSum[i-1] + nums[i-1];
        }
        mergeSort(preSum, 0, n+1);
        return ans;
    }
    
    void mergeSort(vector<long>& vec, int lo, int hi) {
        if (hi - lo <= 1) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(vec, lo, mid);
        mergeSort(vec, mid, hi);
        int m = mid;
        int n = mid;
        for (int i = lo; i < mid; i++) {
            while (m < hi && vec[m] - vec[i] < m_lower) m++;
            while (n < hi && vec[n] - vec[i] <= m_upper) n++;
            ans += (n - m);
        }
        merge(vec, lo, hi, mid);
        //inplace_merge(vec.begin() + lo, vec.begin()+mid, vec.begin()+hi);
    }
    
    void merge(vector<long>& vec, int lo, int hi, int mid) {
        vector<long> tmp_vec;
        int left = lo;
        int right = mid;
        while (left < mid && right < hi) {
            if (vec[left] < vec[right]) {
                tmp_vec.push_back(vec[left]);
                left++;
            }
            else {
                tmp_vec.push_back(vec[right]);
                right++;
            }
        }
        while (left < mid) {
            tmp_vec.push_back(vec[left]);
            left++;
        }
        while (right < hi) {
            tmp_vec.push_back(vec[right]);
            right++;
        }
        for (int i = lo; i < hi; ++i) {
            vec[i] = tmp_vec[i-lo];
        }
    }
};