#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<vector<long>> numbers;
        numbers.push_back({ 0,1,2,3,4,5,6,7,8,9 });
        vector<int> result;
        if (low > high) return result;
        if (high <=9)
        {
            for (auto item:numbers[0])
            {
                if (item >= low && item <= high) result.push_back(item);
            }
            return result;
        }
        generateStepN(numbers, high);
        for (auto item:numbers)
        {
            for (auto elem:item)
            {
                if (elem <= high && elem >= low) result.push_back(elem);
                if (elem > high) break;
            }
        }
        return result;
    }

private: 
    void generateStepN(vector<vector<long>>& container, int highBound) {
        vector<long> tmp;
        bool overflow = false;
        for (auto item:container.back()) {
            long num0 = item * 10 + item % 10 - 1;
            long num1 = item * 10 + item % 10 + 1;
            if (num0 > 2000000000) {
                overflow = true;
                break;
            }
            if(item%10!=0)tmp.push_back(num0);
            if (item != 0&&item % 10 != 9) tmp.push_back(num1);
        }
        container.push_back(tmp);
        if (highBound <= tmp.back() || overflow) return;
        else generateStepN(container, highBound);
    }
};

int main() {
    Solution solve;
    vector<int> result = solve.countSteppingNumbers(0, 2000000000);
    for (auto item:result)
    {
        cout << item << ",";
    }
    cout << endl;
}
