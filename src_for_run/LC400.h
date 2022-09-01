/*
Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
*/

#include "common.h"

class Solution400 {
public:
    int findNthDigit(int n) {
        int base = 9;
        int digit = 1;
        long long prod = base * digit;
        while (n > prod) {
            n -= base * digit;
            base *= 10;
            ++digit;
            prod = (long long)base * digit;
        }
        int num = pow(10, digit-1);
        num += (n-1)/digit;
        int res = (n-1) % digit;
        return to_string(num)[res] - '0';
    }
};