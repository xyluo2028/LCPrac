// Domino and Tromino Tiling
#include "common.h"
/*
divide the problem into 2 parts: fully covered and partially covered
*/
class Solution {
public:
    int MOD = 1e9 + 7;
    int numTilings(int n) {
        if (n <= 2) return n;
        vector<long long> full_cover(n+1, 0);
        vector<long long> part_cover(n+1, 0);
        full_cover[1] = 1;
        full_cover[2] = 2;
        part_cover[2] = 2;
        for (int i = 3; i <= n; ++i) {
            part_cover[i] = (2 * full_cover[i-2] + part_cover[i-1]) % MOD;
            full_cover[i] = (part_cover[i-1] + full_cover[i-1] + full_cover[i-2]) % MOD;
        }
        return (int)full_cover[n];
    }
};