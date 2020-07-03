// LCPrac17.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Ω””ÍÀÆ 
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int result_sum = 0;
        int submax = 0;
        int tracer = 0;
        bool _findpeak = false;
        //find first peak
        height.push_back(0);
        height.insert(height.begin(), 0);
        for (size_t i = 1; i < height.size(); i++)
        {
            if (_ispeak(height, i)) {
                height.erase(height.begin(), height.begin() + i);
                _findpeak = true;
                break;
            }
        }
        if (!_findpeak)return 0;
        while (height.size() > 0)
        {
            for (size_t i = 1; i < height.size()-1; i++)
            {
                if (_ispeak(height, i))
                {
                    if (height[i] >= height[0])
                    {
                        tracer = i;
                        submax = height[0];
                        break;
                    }
                    else if (height[i] > submax) {
                        submax = height[i];
                        tracer = i;
                    }
                }
            }
            //if not find any peaks, break
            if (submax == 0) break;

            result_sum += CalcSum(height, tracer, submax);
            height.erase(height.begin(), height.begin() + tracer);
            tracer = 0;
            submax = 0;

        }
        return result_sum;

    }

private:
    bool _ispeak(vector<int>& height, int pos) {
        if (height[pos] >= height[pos - 1] && height[pos] >= height[pos + 1] && height[pos]>0) return true;
        else return false;
    }

    int CalcSum(vector<int>& tmp,  int pos1, int subpeak) {
        int sum = 0;
        int offset;
        for (int i = 1; i < pos1; i++)
        {
            offset = (subpeak > tmp[i]) ? subpeak - tmp[i] : 0;
            sum = sum + offset;
        }
        return sum;
    }


};

int main()
{
    vector<int> test = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    //vector<int> test = { 3,1,0 };
    Solution solve;
    int result = solve.trap(test);
    cout << result << endl;
}

