class Solution {    //continuous sub-arrays sums equal to target without overlapping
public:
    int maxNonOverlapping(vector<int>& nums, int target) {   
        if (nums.empty()) return 0;
        unordered_map<int, int> prefixsums;
        prefixsums.emplace(0, -1);
        int pole = -1;
        int ans = 0;
        int tmpsum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            tmpsum += nums[i];
            if (prefixsums.count(tmpsum - target) > 0 && prefixsums[tmpsum-target] >= pole) {
                ans++;
                pole = i;
                cout << pole << endl;
            }
            prefixsums[tmpsum] = i;
        }
        return ans;
    }
};

class Solution1 {   //continuous sub-arrays sums equal to target overlapping allowed
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        unordered_map<int, int> prefixsums;
        prefixsums.emplace(0, 1);
        int ans = 0;
        int tmpsum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            tmpsum += nums[i];
            if (prefixsums.count(tmpsum - k) > 0) {
                ans+=prefixsums[tmpsum - k];
            }
            prefixsums[tmpsum]++;
        }
        return ans;
    }
};
