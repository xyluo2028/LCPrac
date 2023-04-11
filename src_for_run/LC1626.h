// Best Team With No Conflicts
#include "common.h"

class SolutionTopDown {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> vec;
        int n = ages.size();
        for (int i = 0; i < n; ++i) {
            vec.push_back(make_pair(ages[i], scores[i]));
        }
        sort(vec.begin(), vec.end());
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return dp(memo, vec, -1, 0);
    }

    int dp(vector<vector<int>>& memo, vector<pair<int, int>>& vec_pair, int prev, int idx) {
        if (idx >= vec_pair.size()) return 0;
        if (memo[prev + 1][idx] > -1) {
            return memo[prev + 1][idx];
        }
        if (prev == -1 || vec_pair[idx].second >= vec_pair[prev].second) {
            memo[prev+1][idx] = max(vec_pair[idx].second + dp(memo, vec_pair, idx, idx + 1), dp(memo, vec_pair, prev, idx + 1));
            return memo[prev+1][idx];
        }
        memo[prev+1][idx] = dp(memo, vec_pair, prev, idx + 1);
        return memo[prev+1][idx];
    }
};

class SolutionBottomUp {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> vec;
        int n = ages.size();
        for (int i = 0; i < n; ++i) {
            vec.push_back(make_pair(ages[i], scores[i]));
        }
        sort(vec.begin(), vec.end());
        vector<int> dp(n, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = vec[i].second;
            ans = ans > dp[i] ? ans : dp[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (vec[j].second <= vec[i].second) {
                    dp[i] = max(dp[i], vec[i].second + dp[j]);
                }
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
        return ans;
    }
};