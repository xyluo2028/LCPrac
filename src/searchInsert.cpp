#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0]) return 0;
        int len = nums.size();
        if (target > nums.back()) return len;
        if (target == nums.back()) return len - 1;
        bool flag = false;
        int start = 0;
        while (!flag)
        {
            flag = Judge(nums, target, start, len);
        }
        int idx = start * 0.5 + len * 0.5;
        if (nums[idx] >= target) return idx;
        else return idx + 1;
    }

private:
    bool Judge(vector<int>& nums, int target, int& idx0, int& idx1) {
        int idx = 0.5 * idx0 + 0.5 * idx1;
        if (nums[idx] == target || (target > nums[idx] && target < nums[idx + 1]) || target > nums[idx - 1] && target < nums[idx]) return true;
        else if (target > nums[idx]) {
            idx0 = idx;
            return false;
        }
        else {
            idx1 = idx;
            return false;
        }
    }
};

int main()
{
    Solution solve;
    vector<int> test = { 1, 4, 6, 7,8,9 };
    int result = solve.searchInsert(test, 6);
    cout << result << endl;
}