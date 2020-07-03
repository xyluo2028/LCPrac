
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len0 = s.length();
        if (len0 < 2) return len0;
        int max_len = 1;
        unordered_set<char> elements;
        int start = 0;
        int offset;
        int tmp_len = 1;
        while (start < len0-max_len)
        {
            if(!elements.empty()) elements.clear();
            elements.emplace(s[start]);
            tmp_len = 1;
            for (size_t i = 1; i < len0-start; i++)
            {
                if (elements.find(s[start + i]) != elements.end()) {
                    
                    break;
                }
                else {
                    elements.emplace(s[start + i]);
                    tmp_len++;
                }
            }
            max_len = max(max_len, tmp_len);
            start++;
        }
        if (!elements.empty()) elements.clear();
        return max_len;
    }

};

int main()
{
    string test_str = "tmmzxaft";
    Solution solve;
    int len_out = solve.lengthOfLongestSubstring(test_str);
    cout << len_out << endl;
    return 0;
}
