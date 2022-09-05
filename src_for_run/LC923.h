/*
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
*/

#include "common.h"

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        int N = arr.size();
        long long ansL = 0;
        for (int i = 0; i < N - 2; ++i) {
            int target_left = target - arr[i];
            int j = i + 1;
            int k = N - 1;
            while (j < k) {
                if (arr[j] + arr[k] < target_left) {
                    ++j;
                } else if (arr[j] + arr[k] > target_left) {
                    --k;
                } else {
                    if (arr[j] != arr[k]) {
                        int j_cnt = 1;
                        int k_cnt = 1;
                        while (arr[j] == arr[j+1]) {
                            ++j_cnt;
                            ++j;
                        }
                        while (arr[k] == arr[k-1]) {
                            ++k_cnt;
                            --k;
                        }
                        ansL += (j_cnt * k_cnt) % mod;
                        ++j;
                        --k;
                    } else {
                        ansL += ((k - j + 1) * (k - j) / 2) % mod;
                        break;
                    }
                }
            }
        } // end for
        int ans = ansL % mod;
        return ans;
    }
};