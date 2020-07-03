// LCPrac10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int k = (int)(len * 0.5);        
        int idx1 = 0;
        int idx2 = 0;
        int result1 = 0;
        int result2 = 0;
        double result;
        while (k>0)
        {
            cmpArray(nums1, nums2, idx1, idx2, k, result1);
            cout << idx1 << " , " << idx2 << " , " << k << " , " << result1 << endl;
        }
        if (len % 2 == 0) {
            cout << "even " << endl;
            if (idx1 == nums1.size()) result2 = nums2[idx2];
            else if (idx2 == nums2.size()) result2 = nums1[idx1];
            else result2 = (nums1[idx1] < nums2[idx2]) ? nums1[idx1] : nums2[idx2];
            result = (result1 + result2) * 0.5;
        }
        else {
            cout << "odd" << endl;
            if (idx1 == nums1.size()) result2 = nums2[idx2];
            else if (idx2 == nums2.size()) result2 = nums1[idx1];
            else result2 = (nums1[idx1] < nums2[idx2]) ? nums1[idx1] : nums2[idx2];
            result = result2;
        }
        cout << result2 << endl;
        return result;
    }

private:
    void cmpArray(vector<int>& nums1, vector<int>& nums2, int& idx1, int& idx2, int& k, int& result1) {
        int len1 = nums1.size() - idx1;
        int len2 = nums2.size() - idx2;
        int offset1;
        int offset2;
        if (len1 == 0) {
            idx2 += k-1;
            result1 = nums2[idx2];
            idx2++;
            k = 0;
            return;
        }
        else if (len2 == 0) {
            idx1 += k-1;
            result1 = nums1[idx1];
            idx1++;
            k = 0;
            return;
        }
        if (k == 1) {
            if (nums1[idx1] > nums2[idx2]) {
                result1 = nums2[idx2];
                idx2++;
            }
            else {
                result1 = nums1[idx1];
                idx1++;
            }
            k = 0;
            return;
        }
        if (len2 > len1) {
            offset1 = (k * 0.5 > len1) ? (len1) : (int)(k * 0.5);
            offset2 = k - offset1;
        }
        else {
            offset2 = (k * 0.5 > len2) ? (len2) : (int)(k * 0.5);
            offset1 = k - offset2;
        }
        cout << offset1 << " " << offset2 << endl;
        if (nums1[offset1 + idx1 - 1] > nums2[offset2 + idx2 - 1]) {
            idx2 += offset2;
            k = k - offset2;
        }
        else
        {
            idx1 += offset1;
            k = k - offset1;
        }
    }
};

int main()
{
    vector<int>test1 = { };
    vector<int>test2 = { 2, 3};
    Solution solve;
    double result = solve.findMedianSortedArrays(test1, test2);
    cout << "final result: " << result << endl;
}

