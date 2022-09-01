#include "common.h"

class Solution42 {
public:
    int trap(vector<int>& height) {
        vector<int> left_bar(height.size(), 0);
        vector<int> right_bar(height.size(), 0);
        int tmpHigh = 0;
        for (int i = 0; i < height.size(); ++i) {
            tmpHigh = tmpHigh < height[i] ? height[i] : tmpHigh;
            left_bar[i] = tmpHigh;
        }
        tmpHigh = 0;
        for (int i = height.size() - 1; i >= 0; --i) {
            tmpHigh = tmpHigh < height[i] ? height[i] : tmpHigh;
            right_bar[i] = tmpHigh;
        }
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            ans += min(left_bar[i], right_bar[i]) - height[i];
        }
        return ans;
    }
};

class SolutionUseStack {
public:
    int trap(vector<int>& height) {
        stack<int> mStk;
        int ans = 0;
        
        for (int i = 0; i < height.size(); ++i) {
            while (!mStk.empty() && height[i] > height[mStk.top()]) {
                int tmpi = mStk.top();
                mStk.pop();
                if (mStk.empty()) break;
                int dist = i - mStk.top() - 1;
                ans += (min(height[i], height[mStk.top()]) - height[tmpi]) * dist;
            }
            mStk.push(i);
        }
        return ans;
    }
};

class Solution2pointers {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0; 
        int right_max = 0;
        int ans = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (left_max <= height[left]) {
                    left_max = height[left];
                } else {
                    ans += left_max - height[left]; 
                }
                ++left;
            } else {
                if (right_max <= height[right]) {
                    right_max = height[right];
                } else {
                    ans += right_max - height[right];
                }
                --right;
            }            
        }
        return ans;
    }
};