/*
algorithm: monotonic stack. time complex O(n)
count the number of subarraies which nums[i] is the minimum value; 
count the number of subarraies which nums[i] is the maximum value;
range is maxmum - minimum 
*/

#include "common.h"

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        stack<int> sk; // store the index
        int len = nums.size(); 
        for (int i = 0; i <= len; ++i) {
            while (!sk.empty() && (i==len || nums[i] < nums[sk.top()])){
                int tmp_i = sk.top();
                sk.pop();
                int tmp_i1 = sk.empty() ? -1 : sk.top();
                ans -= (long long)nums[tmp_i] * (tmp_i - tmp_i1)*(i - tmp_i);
            }
            sk.push(i);
        }
        sk = stack<int>();
        for (int i = 0; i <= len; ++i) {
            while (!sk.empty() && (i==len || nums[i] > nums[sk.top()])){
                int tmp_i = sk.top();
                sk.pop();
                int tmp_i1 = sk.empty() ? -1 : sk.top();
                ans += (long long)nums[tmp_i] * (tmp_i - tmp_i1)*(i - tmp_i);
            }
            sk.push(i);
        }
        return ans;
    }
};