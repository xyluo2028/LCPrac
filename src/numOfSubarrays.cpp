class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        if (arr.empty()) return 0;
        int len = arr.size();
        vector<int> dp(len + 1);
        dp[0] = 0;
        dp[1] = is_odd(arr[0]) ? 1 : 0;
        for (size_t i = 2; i < len+1; i++)
        {
            if (is_odd(arr[i - 1])) dp[i] = i - dp[i - 1];
            else dp[i] = dp[i - 1];
            cout << arr[i - 1] << "," << dp[i] << endl;
        }
        return sum(dp);
    }

private:
    bool is_odd(int elem) {
        if (elem % 2 == 0) return false;
        else return true;
    }
    int sum(vector<int>& vect) {
        int sum0 = 0;
        for (auto item : vect) {
            sum0 += item;
        }
        return sum0;
    }

};
