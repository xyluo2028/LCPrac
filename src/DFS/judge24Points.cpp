#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        float result = 0.0;
        deque<float> dQ;
        for (int i = 0; i < 4; i++) dQ.push_back((float)nums[i]);
        bool judge = false;
        DFS(dQ, judge);
        return judge;


    }

private:
    void DFS(deque<float> nums, bool& judge) {
        float tmp;
        float tmp1;
        int len = nums.size();
        float result1;
        for (size_t j = 0; j < len; j++)
        {
            tmp = nums.front();
            nums.pop_front();
            for (size_t i = 0; i < len-1; i++)
            {
                if (judge) return;
                tmp1 = nums.front();
                nums.pop_front();
                for (size_t k=0; k < 4; k++) {
                    result1 = calc(tmp, tmp1, k);
                    if ((tmp1 == 0 || tmp==0) && k == 3) continue;
                    if (nums.empty() && abs(result1-24) < 0.001) {
                        judge = true;
                        return;
                    }                    
                    else if(!nums.empty()) {
                        nums.push_back(result1);
                        DFS(nums, judge);
                        nums.pop_back();
                    }
                }
                nums.push_back(tmp1);
            }
            nums.push_back(tmp);
        }
        return;              
    }
    float calc(float num1, float num2, size_t type) {
        switch (type)
        {
        case 0:
            return num1 + num2;
        case 1:
            return num1 - num2;
        case 2:
            return num1 * num2;
        case 3:
            return num1 / num2;
        default:
            break;
        }
    }
};


int main()
{
    Solution solve;
    vector<int> test = { 3,3, 8,8 };
    bool result = solve.judgePoint24(test);
    cout << result << endl;
    float a = (float)8/ (float)3;
    float b = (float)3 - a;
    float c = (float)8 / b;
    cout << c << endl;
}
