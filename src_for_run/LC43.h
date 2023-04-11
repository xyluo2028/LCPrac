// Multiply Strings
#include "common.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> ans_vec(n1+n2+1, 0);
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n2; ++j) {
                int digit = (int)(num1[i] - '0') * (int)(num2[j] - '0');
                ans_vec[i+j] += digit;
                ans_vec[i+j+1] += ans_vec[i+j] / 10;
                ans_vec[i+j] = ans_vec[i+j] % 10;
            }
        }
        string ans = "";
        int no_zero_start = n1 + n2;
        while(no_zero_start >= 0 && ans_vec[no_zero_start] == 0) no_zero_start--;
        if (no_zero_start < 0) return "0";
        for (int i = no_zero_start; i >= 0; i--) {
            ans += to_string(ans_vec[i]);
        }
        return ans;
    }
};