#include "common.h"

class Solution84 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monoStk;
        monoStk.push(-1);
        int N = heights.size();
        int ans = 0;
        for (int i = 0; i <= N; ++i) {
            while (monoStk.top() > -1 && (i == N || heights[i] < heights[monoStk.top()])) {
                int tmpi = monoStk.top();
                monoStk.pop();
                int tmpi1 = monoStk.top();
                ans = ans < heights[tmpi] * (i - 1 - tmpi1) ? heights[tmpi] * (i - 1 - tmpi1) : ans;
                //cout << tmpi << " : " << tmpi1 << " : " << ans << endl;
            }
            monoStk.push(i);
        }
        return ans;
    }
};

class SolutionDivideConq {
public:
    int divideConq(vector<int>& heights, int start, int ending) {
        if (start > ending) {
            return -1;
        }
        int minIdx = (start + ending) / 2;
        for (int i = start; i <= ending; ++i) {
            if (heights[i] < heights[minIdx]) minIdx = i;
        }
        int sol = heights[minIdx] * (ending-start+1);
        int sol_left = divideConq(heights, start, minIdx-1);
        int sol_right = divideConq(heights, minIdx+1, ending);
        //cout << sol << "; " << sol_left << "; " << sol_right << endl;
        return max(sol, max(sol_left, sol_right));
    }

    int largestRectangleArea(vector<int>& heights) {
        return divideConq(heights, 0, heights.size()-1);
    }
};