class Solution {  //5478
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int idx1 = 0;
        int idx2 = 0;
        long long sum1 = 0;
        long long sum2 = 0;
        long long ansBig = 0;
        int ans;
        while (idx1 < nums1.size() || idx2 < nums2.size()) {
            if (idx1 < nums1.size() && idx2 < nums2.size()) {
                if (nums1[idx1] > nums2[idx2]) {
                    sum2 += nums2[idx2++];
                }
                else if (nums2[idx2] > nums1[idx1]) {
                    sum1 += nums1[idx1++];
                }
                else {
                    ansBig += sum1 > sum2 ? sum1 : sum2;
                    sum1 = sum2 = 0;
                    ansBig += nums2[idx2];
                    idx1++;
                    idx2++;
                }
            }
            else if (idx1 < nums1.size()) {
                sum1 += nums1[idx1++];
            }
            else if (idx2 < nums2.size()) {
                sum2 += nums2[idx2++];
            }

        }
        long long sumres = ((sum1 > sum2) ? sum1 : sum2);
        ansBig += sumres;
        ans = ansBig % 1000000007;
        return ans;
    }

};

int main()
{
    Solution solve;
    vector<int> test1 = { 1,2,3,4,5 };
    vector<int> test2 = {6,7,8,9,10 };
    int ans = solve.maxSum(test1, test2);
    cout << ans << endl;
}
