// LCPrac20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.empty())return results;
        vector<int> resnums = nums;
        vector<int> tmp_nums;
        int len = nums.size();
        int pos = 0;
        RecurFind(results, tmp_nums, resnums, pos);
        return results;
    }

private:
    void RecurFind(vector<vector<int>>& results, vector<int>& tmp_nums, vector<int>& resnums, int pos) {
        if (resnums.empty()) {
            cout << "find one!" << endl;
            results.push_back(tmp_nums);
            resnums.push_back(tmp_nums.back());
            tmp_nums.pop_back();
            return;
        }
        int tmp_len;
        for (int i = 0; i < resnums.size(); i++) {
            tmp_nums.push_back(resnums[i]);
            resnums.erase(resnums.begin() + i);           
            RecurFind(results, tmp_nums, resnums, i);
        }
        if (!tmp_nums.empty()) {
            resnums.insert(resnums.begin() + pos, tmp_nums.back());
            cout << tmp_nums.back() << endl;
            tmp_nums.pop_back();
        }

    }
};

int main()
{
    Solution solve;
    vector<int> test = { 1,2,3 };
    vector<vector<int>> results = solve.permute(test);

    cout << results[0][0] << endl;
    //for (vector<int>::iterator it = results[0].begin(); it != results[0].end(); ++it) {
    //    cout << *it << endl;
    //}
}

