// Jump Game VII
#include "common.h"

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        int n = s.size();
        queue<int> q;
        q.push(0);
        int pivot = 0;
        while(!q.empty()) {
            int tmp = q.front();
            q.pop();
            int left = tmp + minJump;
            int right = tmp + maxJump;
            if (right < pivot || left >= n) continue;
            if (left < pivot) left = pivot + 1;
            if (right >= n)right = n -1;
            pivot = right;
            for (int i = left; i <= right; ++i) {
                if (s[i] == '0') {
                    if (i == n - 1) return true;
                    q.push(i);
                }
            }
        }
        return false;
    }
};