// LCPrac19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int tmp;
        for (size_t i = 0; i < k; i++)
        {
            for (size_t j = 0; j < len-1-i; j++)
            {
                if (nums[j] > nums[j + 1]) {
                    tmp = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        return nums[len - k];
    }
};

int main()
{
    vector<int> test = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    Solution solve;
    int result = solve.findKthLargest(test, 4);
    cout << result << endl;

}

