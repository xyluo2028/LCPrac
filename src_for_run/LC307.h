// Range Sum Query - Mutable

#include "common.h"

class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(2*n, 0);
        buildTree(nums);
    }
    
    void update(int index, int val) {
        index += n;
        tree[index] = val;
        while (index > 0) {
            int left = index;
            int right = index;
            if (index % 2 == 0) {
                right++;
            }
            if (index % 2 == 1) {
                left--;
            }
            tree[index / 2] = tree[left] + tree[right];
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        left += n;
        right += n;
        while (left <= right) {
            if (left % 2 == 1) {
                ans += tree[left];
                left++;
            }
            if (right % 2 == 0) {
                ans += tree[right];
                right--;
            }
            left *= 0.5;
            right *= 0.5;
        }
        return ans;
    }
private:
    vector<int> tree;
    int n;
    
    void buildTree(vector<int>& nums) {
        for (int i = n, j = 0; i < 2 * n; ++i, ++j) {
            tree[i] = nums[j];
        }
        for (int i = n-1; i >= 0; i--) {
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }
};