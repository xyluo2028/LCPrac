/*
You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. 
For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the 
characters backward if directioni = 0.

Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). 
Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a'
 becomes 'z').

Return the final string after all such shifts to s are applied.
*/

#include "common.h"

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> pref(n+1, 0);
        for (auto& sh : shifts) {
            pref[sh[0]] += sh[2] ? 1 : -1;
            pref[sh[1] + 1] += sh[2] ? -1 : 1;
        }
        int val = 0;
        for (int i = 0; i < n; ++i) {
            val += pref[i];
            if (val > 0) {
                shift(s[i], 1, val);
            } else if (val < 0) {
                shift(s[i], 0, -val);
            }
        }
        return s;
    }
    
    void shift(char& c, int mode, int step) {
        step = step % 26;
        if (mode == 1) {
            if (c + step > 'z') {
                c = 'a' + (step - (int)('z' - c) - 1);
            } else {
                c = c + step;
            }
            
        }
        if (mode == 0) {
            if (c - step < 'a') {
                c = 'z' - (step - (int)(c - 'a') - 1);
            } else {
                c = c - step;
            }
        }
        
    }
};