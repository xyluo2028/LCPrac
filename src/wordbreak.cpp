// LCPrac34.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) return true;
        auto dp = vector <bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];

    }
};

int main()
{
    Solution solve;
    vector<string> worddict = { "a", "b" };
    string s = "ab";
    bool result = solve.wordBreak(s, worddict);
    cout << result << endl;
}


