


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        vector<int> tmp_vec;
        if (target < 3) {
            tmp_vec.push_back(target);
            result.push_back(tmp_vec);
            return result;
        }
        int elem = 1;
        while (true)
        {
            if (vec_sum(tmp_vec) < target) {
                tmp_vec.push_back(elem);
                elem++;
                cout << elem << endl;
            }
            else if (vec_sum(tmp_vec) == target) {
                result.push_back(tmp_vec);
                cout << tmp_vec.size() << endl;
                if (tmp_vec.size() < 3) break;
                popbacks(tmp_vec);
            }
            else {
                tmp_vec.erase(tmp_vec.begin());
            }
        }
        if ((result.back()).size() < 2) result.pop_back();
        return result;
    }

private:
    void popbacks(vector<int>& tmp_vec) {
        int val = 0;
        int idx = 0;
        while (val < tmp_vec.back())
        {
            val += tmp_vec[idx];
            idx++;
        }
        tmp_vec.erase(tmp_vec.begin(), tmp_vec.begin() + idx-1);
    }

    int vec_sum(vector<int> tmp) {
        if (tmp.empty())
        {
            return 0;
        }
        int sum = (tmp.front() + tmp.back())* tmp.size() * 0.5;
        return sum;
    }
};

int main()
{
    int target = 10;

    vector<vector<int>> result;
    Solution solve;
    result = solve.findContinuousSequence(target);
    cout << result[0][0] << endl;
    return 0;
}

