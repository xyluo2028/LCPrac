// Accounts Merge
/*
Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
*/
#include "common.h"
class Solution {
public:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent_emails;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        for (auto& account : accounts) {
            string first_email = account[1];
            for (int i = 2; i < account.size(); ++i) {
                adjacent_emails[first_email].push_back(account[i]);
                adjacent_emails[account[i]].push_back(first_email);
            }
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; ++i) {
            if (visited.count(accounts[i][1]) == 0) {
                vector<string> merged_emails({accounts[i][0]});
                dfs(accounts[i][1], merged_emails);
                sort(merged_emails.begin() + 1, merged_emails.end());
                ans.push_back(merged_emails);
            }
        }
        return ans;
    }
    void dfs(string& email, vector<string>& merged_emails) {
        visited.insert(email);
        merged_emails.push_back(email);
        for (string& adj_email : adjacent_emails[email]) {
            if (visited.count(adj_email) == 0) {
                dfs(adj_email, merged_emails);
            }
        }
    }
};